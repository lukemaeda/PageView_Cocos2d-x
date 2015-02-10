//
//  PageViewScene.cpp
//  PageView
//
//  Created by MAEDAHAJIME on 2015/02/11.
//
//

#include "PageViewScene.h"


USING_NS_CC;
using namespace ui;

Scene* PageViewScene::createScene()
{
    auto scene = Scene::create();
    auto layer = PageViewScene::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool PageViewScene::init()
{
    //初期化
    if ( !Layer::init() ) return false;
    
    //画面サイズを取得
    auto windowSize = Director::getInstance()->getWinSize();
    
    //PageViewを作成これにレイアウトを追加していく
    auto pageView = PageView::create();
    pageView->setTouchEnabled(true);
    pageView->setSize(windowSize);
    
    //40ページ作成する
    for (int i = 0; i < 40; i++) {
        
        //レイアウトを作成
        auto layout = Layout::create();
        layout->setSize(windowSize);
        
        // バックグランドカラー
        auto background = LayerColor::create(Color4B::WHITE,
                                             windowSize.width,
                                             windowSize.height);
        
        // バックグランドカラー 第2引数は表示順
        this->addChild(background, 0);
        
        //テキスト
        auto label = Text::create(StringUtils::format("%dﾍﾟｰｼﾞ",(i+1)), "Arial", 100);
        label->setColor(Color3B(Color3B::BLUE));
        label->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height / 2));
        layout->addChild(label);
        
        //レイアウトをaddする
        pageView->addPage(layout);
    }
    
    //イベントリスナーを追加（using namespace ui; しないと参照出来ないので注意）
    pageView->addEventListenerPageView(this, pagevieweventselector(PageViewScene::pageviewCallBack));

    this->addChild(pageView);
    
    return true;
}

//コールバック
void PageViewScene::pageviewCallBack(Ref* sender, PageViewEventType type)
{
    if(type == PAGEVIEW_EVENT_TURNING){
        auto pageView = dynamic_cast<PageView*>(sender);
        //選択されているページをログに出力
        log("%ld",pageView->getCurPageIndex() + 1);
    }
}