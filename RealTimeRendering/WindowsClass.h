//=====================================================================================
// WindowsClass.h
// Windows Class Object. Designed to encapsulate windows creation and clean 
// the winMain function
//=====================================================================================

#pragma once
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <cstdint>
//Added Icon file, it creates a resource.h file to load the icon
#include "resource.h"

class WindowsClass
{
public:
	WindowsClass() = delete; //no default constructor
	WindowsClass(HINSTANCE &hInstance);
	~WindowsClass();

//=====================================================================================
// Variables
//=====================================================================================
private:
	uint32_t screenWidth_;
	uint32_t screenHeight_;
	std::wstring szWindowClass_;
	std::wstring szTitle_;
	HINSTANCE hInstance_;
	HWND hWnd_;

//=====================================================================================
// Member Functions
//=====================================================================================
private:
	bool AdjustSizeAndCreateWindow();
public:
	bool Initialize();
	int Run();
};

