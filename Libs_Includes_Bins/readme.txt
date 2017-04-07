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

4.3) Если с FreeType возникла проблема вида "freetype unresolved external symbol", тогда имеет смысл попробовать самостоятельно собрать библиотеку. Далее по пунктам:
а) Скачать с сайта https://www.freetype.org/ архив последней версии, или взять приложенный архив в Libs_Includes_Bins\freetype-2.7.1.tar
б) Распаковать архив
в) Перейти в builds\windows\vc2010\
г) Открыть проект в visual studio (можно кликом по freetype.sln)
д) Собрать библиотеку (Стандартный хоткей - F7)
е) Перейти в корневой каталог freetype, далее \objs\vc2010\Win32
ж) Стащить отсюда библиотеку freetype271d.lib (если скачана другая версия, может называться по-другому)
з) Перейти в корней каталог freetype, стащить отсюда папку include
и) Добавить пути в Include Directories и LibraryDirectories, как было указано в пунктах 4.1 и 4.2
к) Запустить проект, попробовать собрать. Если проблема остается - гуглить. Можно поискать решение здесь: http://stackoverflow.com/questions/40230731/unresolved-externals-when-compiling-with-freetype