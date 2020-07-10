
// 综合总实验View.h : C综合总实验View 类的接口
//

#pragma once
#include "afxwin.h"

class C综合总实验Set;

class C综合总实验View : public CRecordView
{
protected: // 仅从序列化创建
	C综合总实验View();
	DECLARE_DYNCREATE(C综合总实验View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C综合总实验Set* m_pSet;

// 特性
public:
	C综合总实验Doc* GetDocument() const;

// 操作
public:
	CString path;

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C综合总实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString stunum;
	CString phone;
	CString major;
	CString sex;
	CString birth;
	CString home;
	CString photo;
	CString jar;
	void foo(CImage& image, int& x, int& y, int& wh, int& hh);
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSeek();
	afx_msg void Ondelete();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
};

#ifndef _DEBUG  // 综合总实验View.cpp 中的调试版本
inline C综合总实验Doc* C综合总实验View::GetDocument() const
   { return reinterpret_cast<C综合总实验Doc*>(m_pDocument); }
#endif

