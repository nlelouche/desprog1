/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: MyScene.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "MyScene.h"
//---------------------------------------------------------------------------
MyScene::MyScene(Graphics &rkGraphics)
:
Scene(rkGraphics),
m_kGraphics(&rkGraphics),
m_pkChar(NULL),
m_pkCharAnimIzq(NULL),
m_pkCharAnimDer(NULL),
m_pkBack(NULL),
m_pkFloor(NULL),
fGravity(0),
fPosX(0),
fPosY(0),
fVelocityX(0),
fVelocityY(0),
m_pkTileMap(NULL)
{
	//m_kGraphics = &rkGraphics;
}
//---------------------------------------------------------------------------
bool MyScene::onInit()
{
	// INIT SHAPES

	m_pkFloor = new ForceBOX();
	m_pkFloor->setDim(800,10);
	m_pkFloor->setPosXYZ(0,-285,0.0f);

	// FIN SHAPES

	// INIT SPRITE Y TEXTURE

	m_pkChar = new Sprite();

	m_pkCharText = Texture::Ptr(new Texture("../../res/characterFinal.bmp", D3DCOLOR_XRGB(255,0,255)));
	if(!m_pkGraphics->loadTexture("../../res/characterFinal.bmp",* m_pkCharText))
	{
		return false;
	}
	
	m_pkChar->setTexture(m_pkCharText);
	m_pkChar->setTextureArea(0,0,128,128);
	m_pkChar->setDim(64,64);
	m_pkChar->setPosXYZ(0,-220,1.0f);

	m_pkBack = new Sprite();
	m_pkBackText = Texture::Ptr(new Texture("../../res/background.png", D3DCOLOR_XRGB(0,0,0)));
	if(!m_pkGraphics->loadTexture("../../res/background.png",* m_pkBackText))
	{
		return false;
	}

	m_pkBack->setTexture(m_pkBackText);
	m_pkBack->setTextureArea(0,0,512,512);
	m_pkBack->setDim(800,600);
	m_pkBack->setPosXYZ(0,0,-1.0f);

	// FIN TEXTURE Y SPRITES

	// INIT ANIMATION Y ANIMATION INFO

	m_pkCharAnimInfoDer = AnimationInfo::Ptr(new AnimationInfo());

	m_pkCharAnimInfoDer->addFrame(32,0,32,32);
	m_pkCharAnimInfoDer->addFrame(0,0,32,32);
	m_pkCharAnimInfoDer->addFrame(64,0,32,32);
	m_pkCharAnimInfoDer->addFrame(32,0,32,32);
	m_pkCharAnimInfoDer->addFrame(0,0,32,32);
	m_pkCharAnimInfoDer->setLength(900.0f);
	m_pkCharAnimInfoDer->setLoopable(true);
	m_pkCharAnimDer = new Animation(m_pkCharAnimInfoDer);

	m_pkCharAnimInfoIzq = AnimationInfo::Ptr(new AnimationInfo());

	m_pkCharAnimInfoIzq->addFrame(32,32,32,32);
	m_pkCharAnimInfoIzq->addFrame(0,32,32,32);
	m_pkCharAnimInfoIzq->addFrame(64,32,32,32);
	m_pkCharAnimInfoIzq->addFrame(32,32,32,32);
	m_pkCharAnimInfoIzq->addFrame(0,32,32,32);
	m_pkCharAnimInfoIzq->setLength(900.0f);
	m_pkCharAnimInfoIzq->setLoopable(true);
	m_pkCharAnimIzq = new Animation(m_pkCharAnimInfoIzq);

	m_pkChar->setAnimation(m_pkCharAnimIzq);

	m_pkTileMap = new Map(m_kGraphics);

	m_pkTileMap->loadMap("../../res/mapas/TestCollision/tileset.xml", 
		"../../res/Mapas/TestCollision/TestMap.xml");
	m_pkTileMap->setPos(0, 0, 0);

	// FIN ANIMATION Y ANIMATION INFO Y TILEMAP

	// ADDING ENTITIES Y SET VELOCIDAD Y GRAVEDAD

	addEntity(m_pkBack);
	addEntity(m_pkChar);
	addEntity(m_pkFloor);

	fVelocityX = 0.0f;
	fVelocityY = 0.0f;
	fGravity = 0.006f;

	return true;
}
//---------------------------------------------------------------------------
bool MyScene::onUpdate(float fTimeBetweenFrames)
{
	m_pkChar->Update(fTimeBetweenFrames);
	m_pkCharAnimIzq->Update(fTimeBetweenFrames);
	m_pkCharAnimDer->Update(fTimeBetweenFrames);
	m_pkFloor->Update(fTimeBetweenFrames);

	fPosX = m_pkChar->getPosX();
	fPosY = m_pkChar->getPosY();

	if(m_pkInput->getKeyDown(DIK_RIGHTARROW))
	{
		m_pkChar->setAnimation(m_pkCharAnimDer);
		m_pkChar->setMovingAngle(0.0f);
		fVelocityX += 0.005f;
		m_pkCharAnimDer->Play();
	}
	
	if(m_pkInput->getKeyDown(DIK_LEFTARROW))
	{
		m_pkChar->setAnimation(m_pkCharAnimIzq);
		m_pkChar->setMovingAngle(180.0f);
		fVelocityX -= 0.005f;
		m_pkCharAnimIzq->Play();
	}

	if (m_pkInput->getKeyDown(DIK_UPARROW) && fVelocityY == 0.0f) 
	{
		fVelocityY = 2.0f;
	}

	fVelocityY -= fGravity * fTimeBetweenFrames;

	fPosX += fVelocityX;
	fPosY += fVelocityY;

	m_pkChar->setPosXY(fPosX,fPosY);

	m_pkTileMap->update(fTimeBetweenFrames);
	m_pkTileMap->setLayerVisible(0, true);

	updateCollision();

	return true;
}
//---------------------------------------------------------------------------
void MyScene::onDraw(Graphics & rkGraphics) const
{
	m_pkTileMap->draw();
	
	/*****/
}
//---------------------------------------------------------------------------
bool MyScene::onDeInit()
{
	delete m_pkChar;
	m_pkChar = NULL;

	delete m_pkBack;
	m_pkBack = NULL;

	delete m_pkCharAnimIzq;
	m_pkCharAnimIzq = NULL;

	delete m_pkCharAnimDer;
	m_pkCharAnimDer = NULL;

	delete m_pkFloor;
	m_pkFloor = NULL;

	delete m_pkTileMap;
	m_pkTileMap = NULL;

	return true;
}
//---------------------------------------------------------------------------
void MyScene::updateCollision()
{
	Entity2D::CollisionResult eResult;
	eResult = m_pkChar->checkCollision(m_pkFloor);

	if(eResult != Entity2D::None)
	{
		if(eResult == Entity2D::Vertical)
		{
			if(fVelocityY < 0.0f)
			{
				fVelocityY = 0.0f;
				m_pkChar->setPosY(m_pkFloor->getPosY() + m_pkFloor->getDimHeight() / 2 + m_pkChar->getDimHeight() / 2);
			}
		}
	}

	eResult = m_pkTileMap->checkMapCollision(m_pkChar);

	if(eResult != Entity2D::None)
	{
		if(eResult == Entity2D::Vertical)
		{
			if(fVelocityY < 0.0f)
			{
				fVelocityY = 0.0f;
				m_pkChar->setPosY(m_pkTileMap->getPosY() + m_pkTileMap->getTileHeight() / 2 + m_pkChar->getDimHeight() / 2);
			}
		}

		if(eResult == Entity2D::Horizontal)
		{
			if(fVelocityY < 0.0f)
			{
				fVelocityY = 0.0f;
				m_pkChar->setPosX(m_pkTileMap->getPosX() + m_pkTileMap->getTileWidth() / 2 + m_pkChar->getDimHeight() / 2);
			}
		}
	}
}
//---------------------------------------------------------------------------
MyScene::~MyScene()
{
	/*****/
}
//---------------------------------------------------------------------------