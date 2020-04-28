
// 第五周实验第二题View.h : C第五周实验第二题View 类的接口
//

#pragma once


class C第五周实验第二题View : public CView
{
protected: // 仅从序列化创建
	C第五周实验第二题View();
	DECLARE_DYNCREATE(C第五周实验第二题View)

// 特性
public:
	C第五周实验第二题Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;

	int m_nWidth;

	int m_nHeight;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第五周实验第二题View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 第五周实验第二题View.cpp 中的调试版本
inline C第五周实验第二题Doc* C第五周实验第二题View::GetDocument() const
   { return reinterpret_cast<C第五周实验第二题Doc*>(m_pDocument); }
#endif

