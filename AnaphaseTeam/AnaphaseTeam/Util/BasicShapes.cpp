#include "BasicShapes.h"

// コンストラクタ
BasicShapeMesh::BasicShapeMesh(unsigned int vertexCount, unsigned int indexCount, GLenum primitive) :
	vertices_(vertexCount), indices_(indexCount), primitive_(primitive) {
}

// インデックスの取得
void* BasicShapeMesh::indices() const {
	return (void*)&indices_[0];
}

// 頂点座標の取得
void* BasicShapeMesh::positions() const {
	return (void*)&vertices_[0].m_Position;
}

// 法線ベクトルの取得
void* BasicShapeMesh::normals() const {
	return (void*)&vertices_[0].normal;
}

// テクスチャ座標の取得
void* BasicShapeMesh::texcoords() const {
	return (void*)&vertices_[0].texcoord;
}

// 接ベクトルの取得
void* BasicShapeMesh::tangents() const {
	return (void*)&vertices_[0].tangent;
}

// 従法線ベクトルの取得
void* BasicShapeMesh::binormals() const {
	return (void*)&vertices_[0].binormal;
}

// 頂点データの間隔を取得
int BasicShapeMesh::vertexStride() const {
	return sizeof( vertices_[0] );
}

// インデックスデータのサイズを取得
int BasicShapeMesh::indexSize() const {
	return sizeof( indices_[0] );
}

// 頂点数の取得
int BasicShapeMesh::vertexCount() const {
	return (int)vertices_.size();
}

// インデックス数の取得
int BasicShapeMesh::indexCount() const {
	return (int)indices_.size();
}

// インデックスタイプの取得
GLenum BasicShapeMesh::indexType() const {
	return GL_UNSIGNED_SHORT;
}

// プリミティブタイプの取得
GLenum BasicShapeMesh::primitive() const {
	return primitive_;
}

// 回転体のインデックスを作成
void BasicShapeMesh::revolutionizeIndices(IndexBuffer& indices, int slices, int stacks) {
	unsigned int idx = 0;
	unsigned short index = 0;
	for (int i=0; i < slices; ++i) {
		for (int j=0; j < stacks; ++j) {
			indices[idx++] = index;
			indices[idx++] = index + 1;
			indices[idx++] = index + stacks + 2;
			indices[idx++] = index + stacks + 1;
			++index;
		}
		++index;
	}
}

// 描画
void BasicShapeMesh::draw(const VertexAttribute& attribute) const {
	// 頂点データの設定
	if (attribute.m_Position != -1) {
		glEnableVertexAttribArray(attribute.m_Position);
		glVertexAttribPointer(attribute.m_Position, 3, GL_FLOAT, GL_FALSE, vertexStride(), positions());
	}
	if (attribute.normal != -1) {
		glEnableVertexAttribArray(attribute.normal);
		glVertexAttribPointer(attribute.normal, 3, GL_FLOAT, GL_FALSE, vertexStride(), normals());
	}
	if (attribute.texcoord != -1) {
		glEnableVertexAttribArray(attribute.texcoord);
		glVertexAttribPointer(attribute.texcoord, 2, GL_FLOAT, GL_FALSE, vertexStride(), texcoords());
	}
	if (attribute.tangent != -1) {
		glEnableVertexAttribArray(attribute.tangent);
		glVertexAttribPointer(attribute.tangent, 3, GL_FLOAT, GL_FALSE, vertexStride(), tangents());
	}
	if (attribute.binormal != -1) {
		glEnableVertexAttribArray(attribute.binormal);
		glVertexAttribPointer(attribute.binormal, 3, GL_FLOAT, GL_FALSE, vertexStride(), binormals());
	}
	// 描画
	glDrawElements(primitive(), indexCount(), indexType(), indices());
	// 頂点データを無効にする
	if (attribute.m_Position != -1) glDisableVertexAttribArray(attribute.m_Position);
	if (attribute.normal   != -1) glDisableVertexAttribArray(attribute.normal);
	if (attribute.texcoord != -1) glDisableVertexAttribArray(attribute.texcoord);
	if (attribute.tangent  != -1) glDisableVertexAttribArray(attribute.tangent);
	if (attribute.binormal != -1) glDisableVertexAttribArray(attribute.binormal);
}

// 描画
void BasicShapeMesh::draw() const {
	glPushAttrib(GL_ENABLE_BIT);
	glEnable(GL_NORMALIZE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, vertexStride(), positions());
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, vertexStride(), normals());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, vertexStride(), texcoords());
	glEnableVertexAttribArray(14);
	glVertexAttribPointer(14, 3, GL_FLOAT, GL_FALSE, vertexStride(), binormals());
	glEnableVertexAttribArray(15);
	glVertexAttribPointer(15, 3, GL_FLOAT, GL_FALSE, vertexStride(), tangents());
	glDrawElements(primitive(), indexCount(), indexType(), indices());
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableVertexAttribArray(14);
	glDisableVertexAttribArray(15);
	glPopAttrib();
}

// 球体メッシュコンストラクタ
SphereMesh::SphereMesh(float radius, int slices, int stacks)
	: BasicShapeMesh((slices+1) * (stacks+1), slices * stacks * 4) {
	// 頂点データの作成
	int idx = 0;
	for (int i = 0; i <= slices; ++i) {
		float ti = (float)i / slices;
		GSmatrix4 ry;
		ry.identity().rotateY(LERP(ti, 0.0f, 360.0f));
		for (int j = 0; j <= stacks; ++j) {
			float tj = (float)j / stacks;
			float angle = LERP(tj,90.0f, -90.0f);
			float vx = gsCos(angle);
			float vy = gsSin(angle);
			vertices_[idx].m_Position = GSvector3(vx * radius, vy * radius, 0.0) * ry;
			vertices_[idx].normal = GSvector3(vx, vy, 0.0) * ry;
			vertices_[idx].tangent = GSvector3(0.0f, 0.0f, -1.0f) * ry;
			vertices_[idx].binormal = vertices_[idx].tangent.cross(vertices_[idx].normal) * ry;
			vertices_[idx].texcoord = GSvector2(LERP(ti, 0.0, 1.0), LERP(tj, 0.0, 1.0));
			++idx;
		}
	}
	// インデックスの作成
	revolutionizeIndices(indices_, slices, stacks);
}

// トーラスメッシュコンストラクタ
TorusMesh::TorusMesh(float innerRadius, float outerRadius, int sides, int rings)
	: BasicShapeMesh((sides+1) * (rings+1), sides * rings * 4) {
	// 頂点データの作成
	float radius = (outerRadius - innerRadius) / 2.0f;
	float x = (outerRadius + innerRadius) / 2.0f;
	int idx = 0;
	for (int i = 0; i <= rings; ++i) {
		float ti = (float)i / rings;
		GSmatrix4 ry;
		ry.identity().rotateY(LERP(ti, 0.0f, 360.0f)).rotateX(90.0f);
		for (int j = 0; j <= sides; ++j) {
			float tj = (float)j / sides;
			float angle = LERP(tj, 180.0f, -180.0f);
			float vx = gsCos(angle);
			float vy = gsSin(angle);
			vertices_[idx].m_Position = GSvector3(vx * radius + x, vy * radius, 0.0f) * ry;
			vertices_[idx].normal = GSvector3(vx, vy, 0.0f) * ry;
			vertices_[idx].tangent = GSvector3(0.0f, 0.0f, -1.0f) * ry;
			vertices_[idx].binormal = vertices_[idx].tangent.cross(vertices_[idx].normal) * ry;
			vertices_[idx].texcoord = GSvector2(LERP(ti, 0.0f, 1.0f), LERP(tj, 0.0f, 1.0f));
			++idx;
		}
	}
	// インデックスの作成
	revolutionizeIndices(indices_, sides, rings);
}

// 円柱メッシュコンストラクタ
CylinderMesh::CylinderMesh(float radius, float height, int sides)
	: BasicShapeMesh((sides+1)*6, sides*5*4) {
	static const Vertex v[] = {
		{ GSvector3(0.0, 0.5, 0.0), GSvector3(0.0, 1.0, 0.0), GSvector2(0.0, 0.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 1.0, 0.0, 0.0) },
		{ GSvector3(1.0, 0.5, 0.0), GSvector3(0.0, 1.0, 0.0), GSvector2(0.0, 1.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 1.0, 0.0, 0.0) },
		{ GSvector3(1.0, 0.5, 0.0), GSvector3(1.0, 0.0, 0.0), GSvector2(0.0, 0.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 0.0,-1.0, 0.0) },
		{ GSvector3(1.0,-0.5, 0.0), GSvector3(1.0, 0.0, 0.0), GSvector2(0.0, 1.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 0.0,-1.0, 0.0) },
		{ GSvector3(1.0,-0.5, 0.0), GSvector3(0.0,-1.0, 0.0), GSvector2(0.0, 1.0), GSvector3(0.0, 0.0, -1.0), GSvector3(-1.0, 0.0, 0.0) },
		{ GSvector3(0.0,-0.5, 0.0), GSvector3(0.0,-1.0, 0.0), GSvector2(0.0, 0.0), GSvector3(0.0, 0.0, -1.0), GSvector3(-1.0, 0.0, 0.0) },
	};
	// 頂点データの作成
	int idx = 0;
	for (int i = 0; i <= sides; ++i) {
		float ti = (float)i / sides;
		GSmatrix4 ry;
		ry.identity().rotateY(LERP(ti, 0.0f, 360.0f));
		for (int j = 0; j < ARRAY_LENGTH(v); ++j) {
			GSvector3 m_Position( v[j].m_Position.x * radius, v[j].m_Position.y * height, v[j].m_Position.z );
			vertices_[idx].m_Position = m_Position * ry;
			vertices_[idx].normal = v[j].normal * ry;
			vertices_[idx].tangent = v[j].tangent * ry;
			vertices_[idx].binormal = v[j].binormal * ry;
			vertices_[idx].texcoord = GSvector2(LERP(ti, 0.0, 1.0), v[j].texcoord.y);
			++idx;
		}
	}
	// インデックスの作成
	revolutionizeIndices(indices_, sides, ARRAY_LENGTH(v)-1);
}

// 直方体メッシュコンストラクタ
BoxMesh::BoxMesh(float width, float height, float depth)
	: BasicShapeMesh(24, 24)  {
	static const Vertex v[] = {
		// 正面
		{ GSvector3(-0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		// 右
		{ GSvector3( 0.5f, 0.5f, 0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f, 0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f,-0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f, 0.5f,-0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		// 背面
		{ GSvector3( 0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(0.0f,0.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(0.0f,1.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(1.0f,1.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		{ GSvector3(-0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(1.0f,0.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		// 左
		{ GSvector3(-0.5f, 0.5f,-0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f,-0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f, 0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f, 0.5f, 0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		// 上
		{ GSvector3(-0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		{ GSvector3(-0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		{ GSvector3( 0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		{ GSvector3( 0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		// 下
		{ GSvector3(-0.5f,-0.5f, 0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
		{ GSvector3(-0.5f,-0.5f,-0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
		{ GSvector3( 0.5f,-0.5f,-0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
		{ GSvector3( 0.5f,-0.5f, 0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
	};
	// 頂点データの作成
	for (VertexBuffer::size_type i=0; i < vertices_.size(); ++i) {
		vertices_[i] = v[i];
		vertices_[i].m_Position = GSvector3(v[i].m_Position.x * width, v[i].m_Position.y * height, v[i].m_Position.z * depth); 
	}
	// インデックスの作成
	for (IndexBuffer::size_type i=0; i < indices_.size(); ++i) {
		indices_[i] = (unsigned short)i;
	}
}

// end of file

