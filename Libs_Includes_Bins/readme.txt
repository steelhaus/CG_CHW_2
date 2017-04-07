Подключение библиотек.
Для настройки в visual studio переходим: Project->Properties->Configuration Properties->VC++ Directories.
Далее по одному.
1) glew-1.13.0 (загрузка расширений openGL, доступк ним)
	1.1) В Include Directories добавить путь к Libs_Includes_Bins\glew-1.13.0\include
	1.2) В Library Directories добавить путь к Libs_Includes_Bins\glew-1.13.0\lib\Release\Win32
	1.3) Libs_Includes_Bins\glew-1.13.0\bin\Release\Win32\glew32.dll закинуть в папку Debug проекта

2) glm (математика для openGL)
	2.1) В Include Directories добавить путь к Libs_Includes_Bins\glm

3) FreeImage (Поддержка изображений. По большей части используется для текстур)
	3.1) В Include Directories добавить путь к Libs_Includes_Bins\FreeImage
	3.2) В Library Directories добавить путь к Libs_Includes_Bins\FreeImage
	3.3) Libs_Includes_Bins\FreeImage\FreeImage.dll закинуть в папку Debug проекта

4) FreeType (Растеризация шрифтов)
	4.1) В Include Directories добавить путь к Libs_Includes_Bins\FreeType\include
	4.2) В Library Directories добавить путь к Libs_Includes_Bins\FreeType\Win32
