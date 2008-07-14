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
m_pkChar(NULL),
m_pkCharAnim(NULL),
m_pkBack(NULL)
{
	
}
//---------------------------------------------------------------------------
bool MyScene::onInit()
{
	m_pkChar = new Sprite();
	m_pkBack = new Sprite();

	m_pkCharText = Texture::Ptr(new Texture("../../res/character.png",D3DCOLOR_XRGB(0,0,0)));
	if(!m_pkGraphics->loadTexture("../../res/character.png",* m_pkCharText))
	{
		return false;
	}

	m_pkBackText = Texture::Ptr(new Texture("../../res/background.png",NULL));
	if(!m_pkGraphics->loadTexture("../../res/background.png",* m_pkBackText))
	{
		return false;
	}

	m_pkChar->setTexture(m_pkCharText);
	m_pkChar->setTextureArea(0,0,128,128);
	m_pkChar->setDim(64,64);
	m_pkChar->setPosXYZ(0,0,0);

	m_pkBack->setTexture(m_pkBackText);
	m_pkBack->setTextureArea(0,0,512,512);
	m_pkBack->setDim(800,600);
	m_pkBack->setPosXYZ(0,0,0);

	m_pkCharAnimInfo = AnimationInfo::Ptr(new AnimationInfo());
	m_pkCharAnimInfo->addFrame(0,0,32,32);
	m_pkCharAnimInfo->addFrame(32,0,32,32);
	m_pkCharAnimInfo->addFrame(64,0,32,32);
	m_pkCharAnimInfo->addFrame(32,0,32,32);
	m_pkCharAnimInfo->setLength(1000.0f);
	m_pkCharAnimInfo->setLoopable(true);

	m_pkCharAnim = new Animation(m_pkCharAnimInfo);

	m_pkChar->setAnimation(m_pkCharAnim);


	addEntity(m_pkBack);
	addEntity(m_pkChar);

	return true;
}
//---------------------------------------------------------------------------
bool MyScene::onUpdate(float fTimeBetweenFrames)
{
	m_pkBack->Update(fTimeBetweenFrames);
	m_pkChar->Update(fTimeBetweenFrames);

	m_pkCharAnim->Update(fTimeBetweenFrames);

	if(m_pkInput->getKeyDown(DIK_RIGHTARROW))
	{
		m_pkChar->setMoving(true);
		m_pkChar->setMovingSpeed(50.0f);
		m_pkChar->setMovingAngle(0.0f);
		m_pkCharAnim->Play();
	}
	else if(m_pkInput->getKeyDown(DIK_LEFTARROW))
	{
		m_pkChar->setMoving(true);
		m_pkChar->setMovingSpeed(50.0f);
		m_pkChar->setMovingAngle(180.0f);
		m_pkCharAnim->Play();
	}

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
	delete m_pkChar;
	m_pkChar = NULL;

	delete m_pkBack;
	m_pkBack = NULL;

	delete m_pkCharAnim;
	m_pkCharAnim = NULL;

	return true;
}
//---------------------------------------------------------------------------
MyScene::~MyScene()
{
	/***/
}
//---------------------------------------------------------------------------