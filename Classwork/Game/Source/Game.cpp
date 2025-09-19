#include "Framework.h"
#include "Game.h"

Game::Game()
{
    m_pMesh1 = new fw::Mesh( GL_TRIANGLES, { -0.3f,-0.3f,  0.3f,-0.3f,  0.0f,0.3f } );
    m_pMesh2 = new fw::Mesh( GL_LINES, { -0.5f,0.8f,  0.5f,0.8f,  -0.5f,-0.8f,  0.5f,-0.8f } );
}

Game::~Game()
{
    delete m_pMesh1;
    delete m_pMesh2;
}

void Game::update(float deltaTime)
{
    //fw::OutputMessage( "deltaTime is %f\n", deltaTime );
    fw::OutputMessage( "framerate is %f\n", 1.0f/deltaTime );
}

void Game::draw()
{
    glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    m_pMesh1->draw();
    m_pMesh2->draw();
}
