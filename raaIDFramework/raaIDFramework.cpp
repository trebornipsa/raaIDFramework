// raaIDFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <raaIDCore/raaIDCore.h>
#include <raaIDPluginManager/raaIDPluginManager.h>
#include <raaIDDataManager/raaIDDataManager.h>

int main()
{
	raaIDCore::start();
	raaIDPluginManager::start();
	raaIDDataManager::start();

	raaIDPluginManager::instance()->loadPlugins();

	
	raaIDDataManager::stop();
	raaIDPluginManager::stop();
	raaIDCore::stop();

	return 0;
}

