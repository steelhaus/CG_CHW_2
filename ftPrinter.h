#pragma once

#define FT_INFO_FOG				0
#define FT_INFO_LIGHT			1
#define FT_INFO_TIME			2
#define FT_EMPTY				3
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
	ftFont.printFormatted(20, yPos -= 30, 24, "Key '0' for Empty section");
	switch(currentInfo::iInfo){
	case FT_EMPTY:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: EMPTY");
		break;
	case FT_INFO_FOG:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: FOG");
		ftFont.printFormatted(20, yPos -= 50, 24, "Press L to activate Linear fog quation, E for exp fog, X for exp2 fog and N for disable");
		ftFont.printFormatted(20, yPos -= 30, 24, "Current fog type is: %s", FogParameters::iFogEquation == 0 ? "Linear" : (FogParameters::iFogEquation == 1 ? "Exp" : (FogParameters::iFogEquation == 2 ? "Exp2" : "None")));
		switch (FogParameters::iFogEquation){
		case FOG_EQUATION_EXP:
		case FOG_EQUATION_EXP2:
			ftFont.printFormatted(20, yPos -= 50, 24, "Change Fog_density using keys J and U");
			ftFont.printFormatted(20, yPos -= 30, 24, "Current Fog_density is: %.4f", FogParameters::fDensity);
			break;
		case FOG_EQUATION_LINEAR:
			ftFont.printFormatted(20, yPos -= 50, 24, "Change Fog_start using keys J and U; Change Fog_end using keys K and I");
			ftFont.printFormatted(20, yPos -= 30, 24, "Current Fog_start is: %.4f; Current Fog_end is %.4f", FogParameters::fStart, FogParameters::fEnd);
			break;
		}
		break;
	case FT_INFO_LIGHT:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: LIGHT");
		ftFont.printFormatted(20, yPos -= 50, 24, "current direction light angle is: %.2f", dlSun.fAngle);
		ftFont.printFormatted(20, yPos -= 30, 24, "To switch spotlight on/off press key F");
		break;
	case FT_INFO_TIME:
		ftFont.printFormatted(20, yPos -= 30, 24, "selected section is: TIME");
		ftFont.printFormatted(20, yPos -= 50, 24, "press Q to stop time or E to start time");
		ftFont.printFormatted(20, yPos -= 30, 24, "press L to remote time forward or J to remote time backward (for 5 minutes)");
		ftFont.printFormatted(20, yPos -= 30, 24, "press I to speed up inner time or K to slow down. Current state: %.0f seconds in one real second", tmInnerTime.fSecondsInRealSecond);

		//float fr = tmInnerTime.getSkyboxColor().r;
		//ftFont.printFormatted(20, yPos -= 30, 24, "gray shade is: %.4f", fr);
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
	if(Keys::Onekey('F')) slFlashLight.bOn = 1-slFlashLight.bOn;	

	switch(currentInfo::iInfo){
	case FT_INFO_FOG:
		if (Keys::Key('L')) FogParameters::iFogEquation = FOG_EQUATION_LINEAR; 
		if (Keys::Key('E')) FogParameters::iFogEquation = FOG_EQUATION_EXP;
		if (Keys::Key('X')) FogParameters::iFogEquation = FOG_EQUATION_EXP2; 
		if (Keys::Key('N')) FogParameters::iFogEquation = FOG_DISABLED;
		switch (FogParameters::iFogEquation){
		case FOG_EQUATION_EXP:
		case FOG_EQUATION_EXP2:
			if (Keys::Key('J')) FogParameters::fDensity -= appMain.sof(0.01f);
			if (Keys::Key('U')) FogParameters::fDensity += appMain.sof(0.01f);
			break;
		case FOG_EQUATION_LINEAR:
			if (Keys::Key('J')) FogParameters::fStart -= appMain.sof(15.0f);
			if (Keys::Key('U')) FogParameters::fStart += appMain.sof(15.0f);
			if (Keys::Key('K')) FogParameters::fEnd -= appMain.sof(15.0f);
			if (Keys::Key('I')) FogParameters::fEnd += appMain.sof(15.0f);
			break;
		}
		break;
	case FT_INFO_LIGHT:
		
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
	}

	
}