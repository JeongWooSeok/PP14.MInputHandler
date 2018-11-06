#pragma once
#include "SDL.h"
#include <vector>
#include "InputHandler.h"

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	void onKeyUp();
	void onKeyDown();
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);


	// mouse buttion events								
	std::vector<bool> m_mouseButtonStates;

	// mouse motion event					
	Vector2D* m_mousePosition;
private:

	const Uint8* m_keystates; // keyboard specific
	
	enum mouse_buttons //mouse specific
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;
