#pragma once

#define FT_INFO_FOG				0
#define FT_INFO_LIGHT			1
#define FT_INFO_TIME			2
#define FT_EMPTY				3
#define FT_PARTICLE				4
namespace currentInfo{
	int iInfo = FT_EMPTY;
	int secondsKeyTick = 0;
};

void ftPrintAllInfo(COpenGLControl* oglControl){
	glDisable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	spFont2D.UseProgram();
	spFont2D.SetUniform("vColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	spFont2D.SetUniform("projectionMatrix", oglControl->GetOrthoMatrix());
	int width = oglControl->GetViewportWidth(), 
		height = oglControl->GetViewportHeight();
	float fullHours = tmInnerTime.getFullHours();
	float fullMinutes = tmInnerTime.getFullMinutes();
	float fullSeconds = tmInnerTime.getFullSeconds();
	int yPos = height;
	ftFont.printFormatted(20, yPos -= 30, 24, "World time %.0f:%.0f:%.0f", fullHours, fullMinutes, fullSeconds);
	ftFont.printFormatted(20, yPos -= 50, 24, "Use Key '1' for Fog section, Key '2' for Light section, Key '3' for Time section,");
	ftFont.printFormatted(20, yPos -= 30, 24, "Key '0' for Empty section, Key '4' for Particle section");
	switch(currentInfo::iInfo){
	case FT_EMPTY:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: EMPTY");
		ftFont.printFormatted(20, yPos -= 50, 24, "boat pitch is: %.4f", fBoatPitch);
		break;
	case FT_INFO_FOG:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: FOG");
		ftFont.printFormatted(20, yPos -= 30, 24, "Press O to turn fog on/off. It is %s now", (cfWorldFog.bFogEnabled_view ? "ON" : "OFF"));
		ftFont.printFormatted(20, yPos -= 30, 24, "Press G turn on/off fog gradually changing. It is %s now", (cfWorldFog.bGraduallyFogChanging ? "ON" : "OFF"));
		ftFont.printFormatted(20, yPos -= 50, 24, "Press L to activate Linear fog quation, E for exp fog, X for exp2 fog");
		ftFont.printFormatted(20, yPos -= 30, 24, "Current fog type is: %s", 
			cfWorldFog.getFogEquationType() == FOG_TYPE_LINEAR ? "Linear" : (
			cfWorldFog.getFogEquationType() == FOG_TYPE_EXP ? "Exp" : (
			cfWorldFog.getFogEquationType() == FOG_TYPE_EXP2 ? "Exp2" : "Unknown")));		
		switch (cfWorldFog.getFogEquationType()){
		case FOG_TYPE_EXP:
		case FOG_TYPE_EXP2:
			ftFont.printFormatted(20, yPos -= 50, 24, "Change max Fog_density using keys J and U");
			ftFont.printFormatted(20, yPos -= 30, 24, "Max Fog_density is: %.4f", cfWorldFog.getDensity());
			ftFont.printFormatted(20, yPos -= 30, 24, "Current Fog_density is: %.4f", cfWorldFog.getCurrentDensity());
			break;
		case FOG_TYPE_LINEAR:
			ftFont.printFormatted(20, yPos -= 50, 24, "Change Fog_start using keys J and U; Change Fog_end using keys K and I");
			ftFont.printFormatted(20, yPos -= 30, 24, "Current Fog_start is: %.4f; Current Fog_end is %.4f", cfWorldFog.getStart(), cfWorldFog.getEnd());//FogParameters::fStart, FogParameters::fEnd);
			break;
		}
		break;
	case FT_INFO_LIGHT:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: LIGHT");
		ftFont.printFormatted(20, yPos -= 50, 24, "current direction light angle is: %.2f", dlSun.fAngle);
		ftFont.printFormatted(20, yPos -= 30, 24, "To switch spotlight on/off press key F");
		ftFont.printFormatted(20, yPos -= 30, 24, "Press R/G/B/N to turn on/off red/green/blue/white point lights");
		ftFont.printFormatted(20, yPos -= 50, 24, "Press Ctrl + R/G/B/N to posess light");
		break;
	case FT_INFO_TIME:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: TIME");
		ftFont.printFormatted(20, yPos -= 50, 24, "press Q to stop time or E to start time");
		ftFont.printFormatted(20, yPos -= 30, 24, "press L to remote time forward or J to remote time backward (for 5 minutes)");
		ftFont.printFormatted(20, yPos -= 30, 24, "press I to speed up inner time or K to slow down. Current state: %.0f seconds in one real second", tmInnerTime.fSecondsInRealSecond);
		break;
	case FT_PARTICLE:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: PARTICLES");
		ftFont.printFormatted(20, yPos -= 50, 24, "press I and K to change singing fountain radius");
		break;
	}

	ftFont.print("Tochilin Anatoly, group 132", 20, 20, 24);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void ftCheckKeyPressing(){
	if (Keys::Key('1')) currentInfo::iInfo = FT_INFO_FOG;
	if (Keys::Key('2')) currentInfo::iInfo = FT_INFO_LIGHT;
	if (Keys::Key('3')) currentInfo::iInfo = FT_INFO_TIME;
	if (Keys::Key('0')) currentInfo::iInfo = FT_EMPTY;
	if (Keys::Key('4')) currentInfo::iInfo = FT_PARTICLE;
	if(Keys::Onekey('F')) slFlashLight.bOn = 1-slFlashLight.bOn;	

	switch(currentInfo::iInfo){
	case FT_INFO_FOG:
		if (Keys::Onekey('G')) cfWorldFog.bGraduallyFogChanging = !cfWorldFog.bGraduallyFogChanging;
		
		if (Keys::Key('L')) cfWorldFog.setEquationType(FOG_TYPE_LINEAR);
		if (Keys::Key('E')) cfWorldFog.setEquationType(FOG_TYPE_EXP);
		if (Keys::Key('X')) cfWorldFog.setEquationType(FOG_TYPE_EXP2);
		if (Keys::Onekey('O')){
			cfWorldFog.bFogEnabled_view = !cfWorldFog.bFogEnabled_view;
			if (cfWorldFog.bFogEnabled == FOG_ENABLED_FALSE){ //если отключен, то включаем
				cfWorldFog.bFogEnabled = FOG_ENABLED_TRUE; //включаем
				cfWorldFog.fogStatus = FOG_STATUS_INCREASING; //запускаем возрастание
			} else if (cfWorldFog.fogStatus == FOG_STATUS_STABLE){ //если не изменяется, значит максимальный
				cfWorldFog.fogStatus = FOG_STATUS_DECREASING;
			} else if (cfWorldFog.fogStatus == FOG_STATUS_INCREASING){ //возрастает сейчас, значит отправляем в убывание
				cfWorldFog.fogStatus = FOG_STATUS_DECREASING;
			} else if (cfWorldFog.fogStatus == FOG_STATUS_DECREASING){ //убывает сейчас, отправляем в возрастание
				cfWorldFog.fogStatus = FOG_STATUS_INCREASING;
			}
		}
		switch (cfWorldFog.getFogEquationType()){
		case FOG_TYPE_EXP:
		case FOG_TYPE_EXP2:
			if (Keys::Key('J')) cfWorldFog.addDensity(-1.0f * appMain.sof(0.01f));
			if (Keys::Key('U')) cfWorldFog.addDensity(appMain.sof(0.01f));
			break;
		case FOG_TYPE_LINEAR:
			if (Keys::Key('J')) cfWorldFog.addStart(-1.0f * appMain.sof(15.0f));
			if (Keys::Key('U')) cfWorldFog.addStart(appMain.sof(15.0f));
			if (Keys::Key('K')) cfWorldFog.addEnd(-1.0f * appMain.sof(15.0f));
			if (Keys::Key('I')) cfWorldFog.addEnd(appMain.sof(15.0f));
			break;
		}
		break;
	case FT_INFO_LIGHT:
		if (!Keys::Key(VK_CONTROL) && Keys::Onekey('R')) plLightRed.bTurnedOn = 1 - plLightRed.bTurnedOn;
		if (!Keys::Key(VK_CONTROL) && Keys::Onekey('G')) plLightGreen.bTurnedOn = 1 - plLightGreen.bTurnedOn;
		if (!Keys::Key(VK_CONTROL) && Keys::Onekey('B')) plLightBlue.bTurnedOn = 1 - plLightBlue.bTurnedOn;
		if (!Keys::Key(VK_CONTROL) && Keys::Onekey('N')) plLightWhite.bTurnedOn = 1 - plLightWhite.bTurnedOn;
		if (Keys::Key('I')) currentPosessedLight->vPosition.z += appMain.sof(20.0f);
		if (Keys::Key('K')) currentPosessedLight->vPosition.z -= appMain.sof(20.0f);
		if (Keys::Key('J')) currentPosessedLight->vPosition.x += appMain.sof(20.0f);
		if (Keys::Key('L')) currentPosessedLight->vPosition.x -= appMain.sof(20.0f);
		if (Keys::Key('U')) currentPosessedLight->vPosition.y -= appMain.sof(20.0f);
		if (Keys::Key('O')) currentPosessedLight->vPosition.y += appMain.sof(20.0f);
		if (Keys::Key(VK_CONTROL) && Keys::Key('R')) currentPosessedLight = &plLightRed;
		if (Keys::Key(VK_CONTROL) && Keys::Key('G')) currentPosessedLight = &plLightGreen;
		if (Keys::Key(VK_CONTROL) && Keys::Key('B')) currentPosessedLight = &plLightBlue;
		if (Keys::Key(VK_CONTROL) && Keys::Key('N')) currentPosessedLight = &plLightWhite;
		break;
	case FT_INFO_TIME:
		if (Keys::Key('Q')) enableDayNightSelfAlternation = false;
		if (Keys::Key('E')) enableDayNightSelfAlternation = true;
		if (Keys::Key('J')) {
			tmInnerTime.addInnerTime(-300);
			dlSun.fAngle = tmInnerTime.getSunAngle();
			dlSun.updateLightProperties();
		}
		if (Keys::Key('L')) {
			tmInnerTime.addInnerTime(300);
			dlSun.fAngle = tmInnerTime.getSunAngle();
			dlSun.updateLightProperties();
		}
		if (Keys::Key('I')) {
			currentInfo::secondsKeyTick += 1;
			if (currentInfo::secondsKeyTick < 20) tmInnerTime.fSecondsInRealSecond += 1;
			else if (currentInfo::secondsKeyTick < 30) tmInnerTime.fSecondsInRealSecond += 5;
			else if (currentInfo::secondsKeyTick < 50) tmInnerTime.fSecondsInRealSecond += 10;
			else if (currentInfo::secondsKeyTick < 80) tmInnerTime.fSecondsInRealSecond += 50;
			else tmInnerTime.fSecondsInRealSecond += 100;
		} else if (Keys::Key('K')){
			currentInfo::secondsKeyTick += 1;
			if (currentInfo::secondsKeyTick < 20) tmInnerTime.fSecondsInRealSecond -= 1;
			else if (currentInfo::secondsKeyTick < 30) tmInnerTime.fSecondsInRealSecond -= 5;
			else if (currentInfo::secondsKeyTick < 50) tmInnerTime.fSecondsInRealSecond -= 10;
			else if (currentInfo::secondsKeyTick < 80) tmInnerTime.fSecondsInRealSecond -= 50;
			else tmInnerTime.fSecondsInRealSecond -= 100;
		} else {
			currentInfo::secondsKeyTick = 0;
		}
		break;
	case FT_PARTICLE:
		float fDelta = appMain.sof(20.0);
		if (Keys::Key('L')) psSingingFountain.addGeneratorVelocity(glm::vec3(-fDelta,0.0f,-fDelta), glm::vec3(fDelta,0.0f,fDelta));
		if (Keys::Key('J')) psSingingFountain.addGeneratorVelocity(glm::vec3(fDelta,0.0f,fDelta), glm::vec3(-fDelta,0.0f,-fDelta));
		if (Keys::Key('I')) psSingingFountain.addGeneratorVelocity(glm::vec3(0.0f,fDelta/2,0.0f), glm::vec3(0.0f,fDelta/2,0.0f));
		if (Keys::Key('K')) psSingingFountain.addGeneratorVelocity(glm::vec3(0.0f,-fDelta/2,0.0f), glm::vec3(0.0f,-fDelta/2,0.0f));
		break;
	
	}
}