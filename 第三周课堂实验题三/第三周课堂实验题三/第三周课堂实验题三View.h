
// 第三周课堂实验题三View.h : C第三周课堂实验题三View 类的接口
//

#pragma once


class C第三周课堂实验题三View : public CView
{
protected: // 仅从序列化创建
	C第三周课堂实验题三View();
	DECLARE_DYNCREATE(C第三周课堂实验题三View)

// 特性
public:
	C第三周课堂实验题三Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第三周课堂实验题三View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 第三周课堂实验题三View.cpp 中的调试版本
inline C第三周课堂实验题三Doc* C第三周课堂实验题三View::GetDocument() const
   { return reinterpret_cast<C第三周课堂实验题三Doc*>(m_pDocument); }
#endif

