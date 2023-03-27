#pragma once
#include <afxwin.h>
#include "CPntAr.h"
class Graph :
    public CStatic
{
public:
    Graph();
    virtual ~Graph();
    DECLARE_MESSAGE_MAP()
        afx_msg void OnPaint();
};
