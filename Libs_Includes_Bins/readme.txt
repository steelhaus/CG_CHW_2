����������� ���������.
��� ��������� � visual studio ���������: Project->Properties->Configuration Properties->VC++ Directories.
����� �� ������.
1) glew-1.13.0 (�������� ���������� openGL, ������� ���)
	1.1) � Include Directories �������� ���� � Libs_Includes_Bins\glew-1.13.0\include
	1.2) � Library Directories �������� ���� � Libs_Includes_Bins\glew-1.13.0\lib\Release\Win32
	1.3) Libs_Includes_Bins\glew-1.13.0\bin\Release\Win32\glew32.dll �������� � ����� Debug �������

2) glm (���������� ��� openGL)
	2.1) � Include Directories �������� ���� � Libs_Includes_Bins\glm

3) FreeImage (��������� �����������. �� ������� ����� ������������ ��� �������)
	3.1) � Include Directories �������� ���� � Libs_Includes_Bins\FreeImage
	3.2) � Library Directories �������� ���� � Libs_Includes_Bins\FreeImage
	3.3) Libs_Includes_Bins\FreeImage\FreeImage.dll �������� � ����� Debug �������

4) FreeType (������������ �������)
	4.1) � Include Directories �������� ���� � Libs_Includes_Bins\FreeType\include
	4.2) � Library Directories �������� ���� � Libs_Includes_Bins\FreeType\Win32

4.3) ���� � FreeType �������� �������� ���� "freetype unresolved external symbol", ����� ����� ����� ����������� �������������� ������� ����������. ����� �� �������:
�) ������� � ����� https://www.freetype.org/ ����� ��������� ������, ��� ����� ����������� ����� � Libs_Includes_Bins\freetype-2.7.1.tar
�) ����������� �����
�) ������� � builds\windows\vc2010\
�) ������� ������ � visual studio (����� ������ �� freetype.sln)
�) ������� ���������� (����������� ������ - F7)
�) ������� � �������� ������� freetype, ����� \objs\vc2010\Win32
�) ������� ������ ���������� freetype271d.lib (���� ������� ������ ������, ����� ���������� ��-�������)
�) ������� � ������ ������� freetype, ������� ������ ����� include
�) �������� ���� � Include Directories � LibraryDirectories, ��� ���� ������� � ������� 4.1 � 4.2
�) ��������� ������, ����������� �������. ���� �������� �������� - �������. ����� �������� ������� �����: http://stackoverflow.com/questions/40230731/unresolved-externals-when-compiling-with-freetype