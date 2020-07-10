
// usinglibdllView.h : CusinglibdllView 类的接口
//

#pragma once


class CusinglibdllView : public CView
{
protected: // 仅从序列化创建
	CusinglibdllView();
	DECLARE_DYNCREATE(CusinglibdllView)

// 特性
public:
	CusinglibdllDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CusinglibdllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usinglibdllView.cpp 中的调试版本
inline CusinglibdllDoc* CusinglibdllView::GetDocument() const
   { return reinterpret_cast<CusinglibdllDoc*>(m_pDocument); }
#endif

