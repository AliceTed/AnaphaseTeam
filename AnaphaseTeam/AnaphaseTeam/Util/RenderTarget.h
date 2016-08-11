#ifndef RENDER_TARGET_H_
#define RENDER_TARGET_H_

#include <opengl_ext.h>

// レンダーターゲットクラス
class RenderTarget {
public:
	// コンストラクタ
	RenderTarget(GLuint width, GLuint height, bool color = true, bool depth = true) :
		frameBuffer_(0),
		colorBuffer_(0),
		depthBuffer_(0) {
		if (color) createColorBuffer(width, height);
		if (depth) createDepthBuffer(width, height);
		glGenFramebuffers(1, &frameBuffer_);
		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer_);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorBuffer_, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthBuffer_, 0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	// デストラクタ
	~RenderTarget() {
		glDeleteTextures(1, &colorBuffer_);
		glDeleteTextures(1, &depthBuffer_);
		glDeleteFramebuffers(1, &frameBuffer_);
	}
	// 描画開始
	void begin() {
		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer_);
	}
	// 描画終了
	void end() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	// カラーバッファの取得
	GLuint colorBuffer() const {
		return colorBuffer_;
	}
	// デプスバッファの取得
	GLuint depthBuffer() const {
		return depthBuffer_;
	}
	// 描画
	void draw() const {
		glPushAttrib(GL_ENABLE_BIT);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f);
			glVertex2f(-1.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex2f(-1.0f, -1.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex2f(1.0f, -1.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex2f(1.0f, 1.0f);
		glEnd();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopAttrib();
	}
private:
	// カラーバッファの作成
	void createColorBuffer(GLuint width, GLuint height) {
		glGenTextures(1, &colorBuffer_);
		glBindTexture(GL_TEXTURE_2D, colorBuffer_);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA, width, height,
			0,
			GL_RGBA, GL_UNSIGNED_BYTE, 0
		);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	// デプスバッファの作成
	void createDepthBuffer(GLuint width, GLuint height) {
		glGenTextures(1, &depthBuffer_);
		glBindTexture(GL_TEXTURE_2D, depthBuffer_);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_DEPTH_COMPONENT32F, width, height,
			0,
			GL_DEPTH_COMPONENT, GL_FLOAT, 0
		);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	// コピー禁止
	RenderTarget(const RenderTarget& other);
	RenderTarget& operator = (const RenderTarget& other);

private:
	// フレームバッファオブジェクト
	GLuint frameBuffer_;
	// カラーバッファ
	GLuint colorBuffer_;
	// デプスバッファ
	GLuint depthBuffer_;
};

#endif

// end of file
