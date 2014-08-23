//
//  CADrawerController.h
//  CartoonHouse
//
//  Created by 栗元峰 on 14-8-20.
//
//

#ifndef __CartoonHouse__CADrawerController__
#define __CartoonHouse__CADrawerController__

#include <iostream>
#include "CAViewController.h"

NS_CC_BEGIN

class CC_DLL CADrawerController: public CAViewController
{
    
public:

    CADrawerController();
    
    virtual ~CADrawerController();
    
    virtual bool initWithController(CAViewController* leftViewController, CAViewController* rightViewController, float division);
    
    void replaceRightViewController(CAViewController* rightViewController);
    
    CAViewController* getLeftViewController();
    
    CAViewController* getRightViewController();
    
    void showLeftViewController(bool animated);
    
    void hideLeftViewController(bool animated);
    
    virtual bool ccTouchBegan(CATouch *pTouch, CAEvent *pEvent);
    
    virtual void ccTouchMoved(CATouch *pTouch, CAEvent *pEvent);
    
    virtual void ccTouchEnded(CATouch *pTouch, CAEvent *pEvent);
    
    virtual void ccTouchCancelled(CATouch *pTouch, CAEvent *pEvent);
    
    CC_PROPERTY(CAView*, m_pBackgroundView, BackgroundView);
    
    CC_SYNTHESIZE_IS(bool, m_bTouchMoved, TouchMoved);
    
protected:
    
    void showBegin();
    
    void hideEnded();
    
    void updateViewFrame();
    
    void scheduleShowAction(float dt);
    
    void scheduleHideAction(float dt);
    
protected:
    
    virtual void viewDidLoad();
    
    virtual void viewDidUnload();
    
    virtual void viewDidAppear();
    
    virtual void viewDidDisappear();
    
    virtual void reshapeViewRectDidFinish();
    
    void setLeftViewController(CAViewController* leftViewController);
    
    void setRightViewController(CAViewController* rightViewController);
    
    CAViewController* m_pLeftViewController;
    
    CAViewController* m_pRightViewController;
    
    CAView* m_pContainer[2];
    
    float m_fDivision;
    
    float m_fCurrDivision;
    
    bool m_bShow;
    
    int m_fOffX;
    
    CCRect m_rShowFrame[2];
    CCRect m_rHideFrame[2];
};

NS_CC_END

#endif /* defined(__CartoonHouse__CADrawerController__) */
