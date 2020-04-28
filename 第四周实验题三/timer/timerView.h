
// timerView.h : CtimerView 类的接口
//

#pragma once


class CtimerView : public CView
{
protected: // 仅从序列化创建
	CtimerView();
	DECLARE_DYNCREATE(CtimerView)

// 特性
public:
	CtimerDoc* GetDocument() const;

// 操作
public:
	CRect rc;
	int flag;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CtimerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // timerView.cpp 中的调试版本
inline CtimerDoc* CtimerView::GetDocument() const
   { return reinterpret_cast<CtimerDoc*>(m_pDocument); }
#endif

