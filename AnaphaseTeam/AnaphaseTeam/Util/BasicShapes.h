#ifndef _BASIC_SHAPES_H_
#define _BASIC_SHAPES_H_

#include <gslib.h>
#include <vector>

// 基本形状メッシュクラス
class BasicShapeMesh {
public:
	// 頂点アトリビュート
	struct VertexAttribute {
		GLint m_Position;		// 頂点座標
		GLint normal;		// 法線ベクトル
		GLint texcoord;		// テクスチャ座標
		GLint tangent;		// 接ベクトル
		GLint binormal;		// 従法線ベクトル
		VertexAttribute() :
			m_Position(-1),
			normal(-1),
			texcoord(-1),
			tangent(-1),
			binormal(-1) {
		}
	};
public:
	// コンストラクタ
	BasicShapeMesh(unsigned int vertexCount, unsigned int indexCount, GLenum primitive = GL_QUADS);
	// 仮想デストラクタ
	virtual ~BasicShapeMesh() {}
	// インデックスの取得
	void* indices() const;
	// 頂点座標の取得
	void* positions() const;
	// 法線ベクトルの取得
	void* normals() const;
	// テクスチャ座標の取得
	void* texcoords() const;
	// 接ベクトルの取得
	void* tangents() const;
	// 従法線ベクトルの取得
	void* binormals() const;
	// 頂点データの間隔を取得
	int vertexStride() const;
	// インデックスデータのサイズを取得
	int indexSize() const;
	// 頂点数の取得
	int vertexCount() const;
	// インデックス数の取得
	int indexCount() const;
	// インデックバッファタイプの取得
	GLenum indexType() const;
	// プリミティブタイプの取得
	GLenum primitive() const;
	// 描画
	void draw(const VertexAttribute& attribute) const;
	// 描画
	void draw() const;

protected:
	// 頂点データ型
	struct Vertex {
		GSvector3 m_Position;	// 頂点座標
		GSvector3 normal;	// 法線ベクトル
		GSvector2 texcoord;	// テクスチャ座標
		GSvector3 tangent;	// 接ベクトル
		GSvector3 binormal;	// 従法線ベクトル
	};
	// 頂点バッファ型
	typedef std::vector<Vertex>	VertexBuffer;
	// インデックスバッファ型
	typedef std::vector<unsigned short> IndexBuffer;

	// 回転体のインデックスを作成する
	static void revolutionizeIndices(IndexBuffer& indices, int slices, int stacks);

protected:
	// 頂点バッファ
	VertexBuffer vertices_;
	// インデックスバッファ
	IndexBuffer indices_;
	// プリミティブタイプ
	GLenum primitive_;
};

// 球体メッシュ
class SphereMesh : public BasicShapeMesh {
public:
	// コンストラクタ
	SphereMesh(float radius=1.0f, int slices=32, int stacks=16);
};

// トーラスメッシュ
class TorusMesh : public BasicShapeMesh {
public:
	// コンストラクタ
	TorusMesh(float innerRadius=0.25f, float outerRadius=1.0f, int sides=32, int rings=32);
};

// 円柱メッシュ
class CylinderMesh : public BasicShapeMesh {
public:
	// コンストラクタ
	CylinderMesh(float radius=1.0f, float height=1.0f, int sides=32);
};

// 直方体メッシュ
class BoxMesh : public BasicShapeMesh {
public:
	// コンストラクタ
	BoxMesh(float width=1.0f, float height=1.0f, float depth=1.0f);
};

#endif

// end of file
