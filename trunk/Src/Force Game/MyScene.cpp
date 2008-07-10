/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: MyScene.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "MyScene.h"
//---------------------------------------------------------------------------
MyScene::MyScene(Graphics & rkGraphics)
:
Scene(rkGraphics),
m_pkSprite(NULL),
m_pkMegaman(NULL)
{
	
}
//---------------------------------------------------------------------------
bool MyScene::onInit()
{
	m_pkSprite = new Sprite();
	m_pkMegamanTex = Texture::Ptr(new Texture("../../res/Megaman.bmp",D3DCOLOR_XRGB(255,0,255)));

	if(!m_pkGraphics->loadTexture("../../res/Megaman.bmp",* m_pkMegamanTex))
	{
		return false;
	}

	m_pkSprite->setTexture(m_pkMegamanTex);
	m_pkSprite->setTextureArea(0,0,1024,1024);
	m_pkSprite->setDim(128,128);
	m_pkSprite->setPosXY(0,0);

	m_pkMegamanAnimInfo = AnimationInfo::Ptr(new AnimationInfo());

	m_pkMegamanAnimInfo->addFrame(160,160,80,80);
	m_pkMegamanAnimInfo->addFrame(240,160,80,80);
	m_pkMegamanAnimInfo->addFrame(320,160,80,80);
	m_pkMegamanAnimInfo->addFrame(400,160,80,80);
	m_pkMegamanAnimInfo->addFrame(480,160,80,80);
	m_pkMegamanAnimInfo->addFrame(540,160,80,80);
	m_pkMegamanAnimInfo->addFrame(620,160,80,80);
	m_pkMegamanAnimInfo->addFrame(700,160,80,80);
	m_pkMegamanAnimInfo->addFrame(780,160,80,80);
	m_pkMegamanAnimInfo->addFrame(860,160,80,80);
	m_pkMegamanAnimInfo->addFrame(0,240,80,80);
	m_pkMegamanAnimInfo->addFrame(80,240,80,80);
	m_pkMegamanAnimInfo->addFrame(160,240,80,80);
	m_pkMegamanAnimInfo->addFrame(240,240,80,80);
	
	m_pkMegamanAnimInfo->setLength(2200.0f);
	m_pkMegamanAnimInfo->setLoopable(false);

	m_pkMegaman = new Animation(m_pkMegamanAnimInfo);

	m_pkSprite->setAnimation(m_pkMegaman);

	addEntity(m_pkSprite);

	return true;
}
//---------------------------------------------------------------------------
bool MyScene::onUpdate(float fTimeBetweenFrames)
{
	m_pkSprite->Update(fTimeBetweenFrames);
	m_pkMegaman->Update(fTimeBetweenFrames);
	m_pkMegaman->Play();

	return true;
}
//---------------------------------------------------------------------------
void MyScene::onDraw(Graphics & rkGraphics) const
{
	/***/
}
//---------------------------------------------------------------------------
bool MyScene::onDeInit()
{
	delete m_pkSprite;
	m_pkSprite = NULL;

	delete m_pkMegaman;
	m_pkMegaman = NULL;

	return true;
}
//---------------------------------------------------------------------------
MyScene::~MyScene()
{
	/***/
}
//---------------------------------------------------------------------------