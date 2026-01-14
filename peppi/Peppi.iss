[Setup]
AppName=Peppi
AppVersion=1.0.0
AppPublisher=Group X
DefaultDirName={autopf}\Peppi
DefaultGroupName=Peppi
OutputDir=output
OutputBaseFilename=PeppiSetup
Compression=lzma
SolidCompression=yes
ArchitecturesInstallIn64BitMode=x64
PrivilegesRequired=admin
UninstallDisplayIcon={app}\peppi.exe

[Files]
Source: "build\peppi.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "build\*.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs
Source: "build\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs
Source: "build\styles\*"; DestDir: "{app}\styles"; Flags: ignoreversion recursesubdirs

[Icons]
Name: "{group}\Peppi"; Filename: "{app}\peppi.exe"
Name: "{autodesktop}\Peppi"; Filename: "{app}\peppi.exe"

[Run]
Filename: "{app}\peppi.exe"; Description: "Käynnistä Peppi"; Flags: nowait postinstall skipifsilent
