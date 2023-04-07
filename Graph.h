#pragma once
#include <afxwin.h>
#include "CPntAr.h"
class Graph :
    public CStatic
{
private:
    bool upperGraph;
public:
    Graph(bool upperGraph);
    virtual ~Graph();
    DECLARE_MESSAGE_MAP()
        afx_msg void OnPaint();
};
