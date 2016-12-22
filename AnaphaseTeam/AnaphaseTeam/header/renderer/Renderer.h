#pragma once
#include "IRenderer.h"
#include "../renderer/define/ViewportDesc.h"
#include "../renderer/define/LightDesc.h"
#include "../renderer/define/BlendFunc.h"

class Renderer : public IRenderer
{
public:
	Renderer();
	virtual ~Renderer();

	// IRenderer を介して継承されました
	virtual void initialize() override;

	virtual void viewport(const ViewportDesc & desc) override;

	virtual void perspective(float fov, float aspect, float near, float far) override;

	virtual void lookAt(const Vector3 & eye, const Vector3 & at, const Vector3 & up) override;

	virtual const ViewportDesc & getViewPort() const override;

	virtual const Matrix4 & getProjectionMatrix() const override;

	virtual const Matrix4 & getViewMatrix() const override;

	virtual const LightDesc& getLight()const override;

	virtual void light(const LightDesc & desc) override;

	virtual Ray caluclateRay(const Vector2 & screenPosition) override;

	virtual void render(const MeshRenderDesc & desc) override;

	virtual void render(const AnimationRenderDesc& desc)override;

	virtual void render(const SkinnedMeshRenderDesc& desc)override;

	virtual void render(const BillBoardRenderDesc & desc) override;

	virtual void render(const SpriteRenderDesc & desc) override;

	virtual void render(const SpriteRectRenderDesc& desc)override;

	virtual void render(const StringRenderDesc & desc) override;

	virtual void render(const RectangleRenderDesc & desc) override;

	virtual void render(const OctreeRenderDesc& desc) override;
	//スカイボックス描画
	virtual void render(const SkyBoxRenderDesc& desc)override;
private:
	void setBlendFunc(BlendFunc blendFunc);
	void renderTexture(ResourceID id,const Color4& color);
	void renderTexture(ResourceID id, const Rect& rect, const Rect& srcRect, const Color4& color);

	Matrix4 mProjectionMatrix;
	Matrix4 mViewMatrix;
	ViewportDesc mViewport;
	LightDesc mLight;
};

