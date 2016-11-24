#pragma once

#include "../renderer/define/ResourceID.h"
#include "../renderer/define/Type.h"
#include <string>

struct ViewportDesc;
struct LightDesc;
struct MeshRenderDesc;
struct AnimationRenderDesc;
struct SkinnedMeshRenderDesc;
struct BillboardRenderDesc;
struct SpriteRenderDesc;
struct StringRenderDesc;
struct RectangleRenderDesc;
class Ray;
enum class TexColorKey;

//レンダラインタフェース
class IRenderer
{
public:
	//仮想デストラクタ
	virtual ~IRenderer() {};
	//初期化
	virtual void initialize() = 0;
	//ビューポート設定
	virtual void viewport(const ViewportDesc& desc) = 0;
	//透視変換行列の設定
	virtual void perspective(float fov, float aspect, float near, float far) = 0;
	//視野変換行列の設定
	virtual void lookAt(const Vector3& eye, const Vector3& at, const Vector3& up) = 0;
	//ビューポートの設定
	virtual const ViewportDesc& getViewPort() const = 0;
	//透視変換行列の取得
	virtual const Matrix4& getProjectionMatrix() const = 0;
	//視野変換行列の取得
	virtual const Matrix4& getViewMatrix()  const = 0;
	//ライトの設定
	virtual void light(const LightDesc& desc) = 0;
	//レイの計算を行う
	virtual Ray caluclateRay(const Vector2&screenPosition) = 0;
	//メッシュの描画
	virtual void render(const MeshRenderDesc& desc) = 0;
	//アニメーションするメッシュの描画
	virtual void render(const AnimationRenderDesc& desc) = 0;
	//シェーダを使用したアニメーションの描画
	virtual void render(const SkinnedMeshRenderDesc& desc) = 0;
	//ビルボードの描画
	virtual void render(const BillboardRenderDesc& desc) = 0;
	//スプライト描画
	virtual void render(const SpriteRenderDesc& desc) = 0;
	//文字列の描画
	virtual void render(const StringRenderDesc& desc) = 0;
	//矩形の描画
	virtual void render(const RectangleRenderDesc& desc) = 0;
};