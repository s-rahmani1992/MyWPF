#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(std::wstring fileName, GPU2D* gpu):gpuRender(gpu), bitmap(NULL)
{
	HRESULT hr;
	IWICImagingFactory* imFactory = NULL;
	hr = CoCreateInstance(CLSID_WICImagingFactory, NULL
		, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&imFactory));
	if (hr != S_OK) {}
	
	IWICBitmapDecoder* decoder = NULL;
	hr = imFactory->CreateDecoderFromFilename(fileName.c_str(), NULL, GENERIC_READ
		, WICDecodeMetadataCacheOnLoad, &decoder);
	if (hr != S_OK) {}

	IWICBitmapFrameDecode* frame = NULL;
	hr = decoder->GetFrame(0, &frame);
	if (hr != S_OK) {}

	IWICFormatConverter* converter = NULL;
	hr = imFactory->CreateFormatConverter(&converter);
	if (hr != S_OK) {}

	hr = converter->Initialize(frame, GUID_WICPixelFormat32bppPBGRA
		, WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeCustom);
	if (hr != S_OK) {}

	hr = gpu->GetRenderTarget()->CreateBitmapFromWicBitmap(converter, NULL, &bitmap);
	if (hr != S_OK)

	imFactory->Release();
	decoder->Release();
	converter->Release();
	frame->Release();
}

SpriteSheet::~SpriteSheet()
{
	bitmap->Release();
}

void SpriteSheet::Draw()
{
	gpuRender->GetRenderTarget()->DrawBitmap(bitmap
		, D2D1::RectF(0.0f, 0.0f, bitmap->GetSize().width, bitmap->GetSize().height), 1.0f
		, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR
		, D2D1::RectF(0.0f, 0.0f, bitmap->GetSize().width, bitmap->GetSize().height));
}
