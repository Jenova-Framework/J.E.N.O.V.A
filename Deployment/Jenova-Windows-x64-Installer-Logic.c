// Jenova Framework Installer Logic v1.6
// Developed by Hamid.Memar 2024-2025

// Configuration
const bool RequiresAdminAccess = false;
const String JenovaRuntimeLatestStableURL = "https://github.com/Jenova-Framework/J.E.N.O.V.A/releases/download/v0.3.5.6-Alpha/Jenova.Framework.0.3.5.6.Alpha.Build.77750.Win64.7z";
const String JenovaRuntimeLatestStableHash = "78b614c653e631ad09ee9b6c3afcea73";

// Global Instances
Instance currentTask = 0;

// Helpers
String GetColorFromPercentage(double percentage)
{
    int startRed = 62;
    int startGreen = 8;
    int startBlue = 168;
    int endRed = 160;
    int endGreen = 112;
    int endBlue = 255;
    int red = (int)(startRed + (endRed - startRed) * (percentage / 100.0));
    int green = (int)(startGreen + (endGreen - startGreen) * (percentage / 100.0));
    int blue = (int)(startBlue + (endBlue - startBlue) * (percentage / 100.0));
    return Format("%02X%02X%02X", red, green, blue);
}
void SimulateFakeProcess(int iterations, int totalTime)
{
    int step = 100 / iterations;
    int waitTime = totalTime / iterations;
    for (int i = 0; i <= 100; i += step) 
	{
        SetTaskProgress(currentTask, i);
        Refresh();
        Wait(waitTime);
    }
}

// Callbacks
void RuntimePackageDownloadCallback(double percentage, Size downloadNow, Size downloadTotal, String downloadSpeed)
{
	SetTaskState(currentTask, Format("%.2lf%% (%ld/%ld) At %s 📥", percentage, downloadNow, downloadTotal, downloadSpeed), Color_Download);
	SetTaskProgress(currentTask, percentage);
	SetTaskBarColor(currentTask, GetColorFromPercentage(percentage));
	Refresh();
}
void RuntimePackageExtractCallback(String stageName, String stageData, Size extractedCount, Size totalCount)
{
	Print("RuntimePackageExtractCallback Called >>>");
	double percentage = ((double)extractedCount / totalCount) * 100;
	if (CompareStrings(stageName, "Extracted"))
	{
		SetTaskState(currentTask, Format("%.2lf%% [%s] (%ld/%ld) 💾", percentage, stageData, extractedCount, totalCount), Color_Download);
		SetTaskProgress(currentTask, percentage);
		SetTaskBarColor(currentTask, GetColorFromPercentage(percentage));
	}
	Wait(250); Refresh(); Wait(500);
}

// Installer Entrypoint
bool InstallJenova()
{
	// Set Total Task Count
	auto totalTaskCount = 10;
	UpdateTaskCounter(0, totalTaskCount);
	
	// Task 1 : Validate Admin Access
	currentTask = CreateNewTask("Validating Admin Privileges", "👮"); Wait(200);
	SimulateFakeProcess(5, 1000);
	bool hasAdminAccess = HasAdministratorAccess();
	if (hasAdminAccess && RequiresAdminAccess)
	{
		SetTaskTitle(currentTask, ColorizeText("Installer has administrator access as required.", Color_Success));
		MarkTaskDone(currentTask, true);
	}
	else if (!hasAdminAccess && RequiresAdminAccess)
	{
		SetTaskTitle(currentTask, ColorizeText("Error : Installer has not administrator access but it's required.", Color_Error));
		MarkTaskFailed(currentTask, false);
		return false;
	}
	else if (hasAdminAccess && !RequiresAdminAccess)
	{
		SetTaskTitle(currentTask, ColorizeText("Attention : Installer has administrator access but it's not required.", Color_Warn));
		SetTaskState(currentTask, "⚠️", "000000");
		SetTaskIcon(currentTask, TaskIcon_Warning);
		SetTaskBarColor(currentTask, Color_Warn);
	}
	else if (!hasAdminAccess && !RequiresAdminAccess)
	{
		SetTaskTitle(currentTask, ColorizeText("Installer has not administrator access and it's not required.", Color_Success));
		MarkTaskDone(currentTask, true);
	}
	UpdateTaskCounter(1, totalTaskCount);

	// Task 2 : Validate Windows Version
	currentTask = CreateNewTask("Validating Operating System", "💻"); Wait(200);
	SimulateFakeProcess(10, 600);
	OperatingSystem os = GetOperatingSystem();
	if (os == OS_Unsupported)
	{
		SetTaskTitle(currentTask, ColorizeText("Error : Installer detected unsupported operating system.", Color_Error));
		MarkTaskFailed(currentTask, false);
		return false;
	}
	else
	{
		SetTaskTitle(currentTask, ColorizeText(Format("Installer detected compatible operating system : %s", GetOperatingSystemName(os)), Color_Success));
		MarkTaskDone(currentTask, true);
	}
	UpdateTaskCounter(2, totalTaskCount);
	
	// Task 3 : Check And Validate Godot Project Path
	String installationPath = GetInstallationPath();
	currentTask = CreateNewTask("Validating Godot Project", "🦋"); Wait(200);
	SimulateFakeProcess(10, 200);
	String godotProjectFile = CombineStrings(installationPath, "/project.godot");
	if (DoesFileExist(godotProjectFile))
	{
		SetTaskTitle(currentTask, ColorizeText("Selected Godot project path is valid.", Color_Success));
		MarkTaskDone(currentTask, true);
	}
	else
	{
		SetTaskTitle(currentTask, ColorizeText("Attention : Selected Godot project path is invalid.", Color_Warn));
		SetTaskState(currentTask, "⚠️", "000000");
		SetTaskIcon(currentTask, TaskIcon_Warning);
		SetTaskBarColor(currentTask, Color_Warn);
	}
	UpdateTaskCounter(3, totalTaskCount);
	
	// Task 4 : Download Latest Jenova Runtime Package
	currentTask = CreateNewTask("Downloading Jenova Runtime Latest Build Package", "Preparing 🚛"); Wait(400);
	SetTaskState(currentTask, "Connecting 📡", Color_Default); Wait(600);
	SetTaskBarColor(currentTask, Color_Download);
	Buffer dataBuffer = 0; Size dataSize = 0;
	if(!DownloadToBuffer(JenovaRuntimeLatestStableURL, &dataBuffer, &dataSize, &RuntimePackageDownloadCallback)) 
	{
		MarkTaskFailed(currentTask, true);
		return false;
	}
	UpdateTaskCounter(4, totalTaskCount); Wait(800);
	MarkTaskDone(currentTask, true);
	
	// Task 5 : Validate Installation Path
	currentTask = CreateNewTask("Validating Installation Path", "📂"); Wait(200);
	SimulateFakeProcess(20, 600);
	if (DoesDirectoryExist(installationPath))
	{
		SetTaskTitle(currentTask, ColorizeText(Format("Installation path '%s' is valid.", installationPath), Color_Success));
		MarkTaskDone(currentTask, true);
	}
	else
	{
		// Create Installation Directory
		SetTaskTitle(currentTask, "Installation Path Not Found, Creating Required Directory...");
		SetTaskState(currentTask, "☀️", Color_Warn); Wait(1600);
		if (!MakeDirectory(installationPath))
		{
			SetTaskTitle(currentTask, ColorizeText("Error : Installer is unable to create required installation directory.", Color_Error));
			MarkTaskFailed(currentTask, false);
			return false;
		}
		SetTaskTitle(currentTask, "Required Installation Directory Created");
		MarkTaskDone(currentTask, true);
	}
	UpdateTaskCounter(5, totalTaskCount);
	
	// Task 6 : Write Package On Disk
	currentTask = CreateNewTask("Cloning Package On Disk", "📦"); Wait(800);
	SimulateFakeProcess(100, 1000);
	String packageFilePath = CombineStrings(installationPath, "/jenova-runtime-pkg.7z");
	Instance packageFileHandle = CreateFile(packageFilePath);
	if (!packageFileHandle)
	{
		SetTaskTitle(currentTask, ColorizeText("Error: Installer is unable to create a clone of the downloaded package.", Color_Error));
		MarkTaskFailed(currentTask, false);
		return false;
	}
	WriteFile(packageFileHandle, dataBuffer, dataSize);
	CloseFile(packageFileHandle);
	SetTaskState(currentTask, "Releasing Buffers ♻️", Color_Default); Refresh(); Wait(1200);
	FreeDownloadBuffer(&dataBuffer);
	MarkTaskDone(currentTask, true);
	UpdateTaskCounter(6, totalTaskCount);
	
	// Task 7 : Validate Package by MD5 Hash
	currentTask = CreateNewTask("Verifying Package", "🪙✨🔓"); Wait(800);
	SimulateFakeProcess(100, 1000);
	String packageHash = GetFileMD5Hash(packageFilePath);
	if (!CompareStrings(packageHash, JenovaRuntimeLatestStableHash))
	{
		SetTaskTitle(currentTask, ColorizeText("Warning: Package hash does not match the verified source.", Color_Warn));
		SetTaskState(currentTask, "⚠️💀", "000000");
		SetTaskIcon(currentTask, TaskIcon_Warning);
		SetTaskBarColor(currentTask, Color_Warn);
	}
	else
	{
		MarkTaskDone(currentTask, true);
	}
	UpdateTaskCounter(7, totalTaskCount);
	
	// Task 8 : Extract and Install Package Content
	currentTask = CreateNewTask("Installing Jenova Runtime Files", "Preparing 🚚"); Wait(400);
	if (!ExtractArchive(packageFilePath, installationPath, &RuntimePackageExtractCallback))
	{
		SetTaskTitle(currentTask, ColorizeText("Error : Installer is unable to extract downloaded package content.", Color_Error));
		MarkTaskFailed(currentTask, false);
		return false;
	}
	SetTaskProgress(currentTask, 100);
	UpdateTaskCounter(8, totalTaskCount); Wait(800);
	MarkTaskDone(currentTask, true);
	
	// Task 9 : Cleaning Up
	currentTask = CreateNewTask("Cleaning Up", "🧹");
	SimulateFakeProcess(5, 1000);
	RemoveFile(packageFilePath);
	UpdateTaskCounter(9, totalTaskCount); Wait(500);
	MarkTaskDone(currentTask, true);

	// Task 10 : Finalizing
	currentTask = CreateNewTask("Finalizing", "💚");
	SimulateFakeProcess(5, 1000);
	String extensionListFile = CombineStrings(installationPath, "/.godot/extension_list.cfg");
	if (DoesFileExist(extensionListFile))
	{
		String extensionListContent = ReadStringFromFile(extensionListFile);
		if (!extensionListContent)
		{
			SetTaskTitle(currentTask, ColorizeText("Error: Installer failed to finalize installation : Read Error.", Color_Error));
			MarkTaskFailed(currentTask, false);
			return false;
		}
		String extensionListNewContent = CombineStrings(extensionListContent, "res://Jenova/Jenova.Runtime.gdextension\n");
		if (!WriteStringToFile(extensionListFile, extensionListNewContent))
		{
			SetTaskTitle(currentTask, ColorizeText("Error: Installer failed to finalize installation : Write Error.", Color_Error));
			MarkTaskFailed(currentTask, false);
			return false;
		}
	}
	else
	{
		if (!WriteStringToFile(extensionListFile, "res://Jenova/Jenova.Runtime.gdextension\n"))
		{
			SetTaskTitle(currentTask, ColorizeText("Error: Installer failed to finalize installation : Write Error.", Color_Error));
			MarkTaskFailed(currentTask, false);
			return false;
		}
	}
	UpdateTaskCounter(10, totalTaskCount); Wait(500);
	MarkTaskDone(currentTask, true);
	Refresh();

	// All Good
	return true;
}
