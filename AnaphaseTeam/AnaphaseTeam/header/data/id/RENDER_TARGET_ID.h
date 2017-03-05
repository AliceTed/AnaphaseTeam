#pragma once

/**
* @file RENDER_TARGET_ID.h
* @brief レンダーターゲット管理用のEnum
* @author 松尾裕也
* @date 2016/3/5
*/
enum class RENDER_TARGET_ID :unsigned int
{
	BASE,
	BRIGHT,
	BLOOM_BLUR,
	BLOOM
};