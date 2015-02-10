//
//  PageViewScene.h
//  PageView
//
//  Created by MAEDAHAJIME on 2015/02/11.
//
//

#ifndef __PageView__PageViewScene__
#define __PageView__PageViewScene__

#include "cocos2d.h"
#include <ui/CocosGUI.h>

class PageViewScene : public cocos2d::Layer
{
    public :
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PageViewScene);
    
    void pageviewCallBack(cocos2d::Ref * psender, cocos2d::ui::PageViewEventType type);
};

#endif /* defined(__PageView__PageViewScene__) */
