#include <fbxsdk.h>
#include <string>
#include <cstring>

int Conversion()
{
    // Initialize the SDK manager
    FbxManager* lSdkManager = FbxManager::Create();

    // Create an FBX importer
    FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

    // Initialize the importer
    std::string IFile = "MyScene.fbx";
    const char* charFile = IFile.c_str();

    if (!lImporter->Initialize(charFile, -1, lSdkManager->GetIOSettings()))
    {
        return 1;
    }

    // Create an FBX scene
    FbxScene* lScene = FbxScene::Create(lSdkManager, "My Scene");

    // Import the scene
    lImporter->Import(lScene);

    // Destroy the importer
    lImporter->Destroy();

    // Create an FBX exporter
    FbxExporter* lExporter = FbxExporter::Create(lSdkManager, "");

    // Initialize the exporter
    if (!lExporter->Initialize("MyExportedScene.fbx", -1, lSdkManager->GetIOSettings()))
    {
        return 1;
    }

    // Export the scene
    lExporter->Export(lScene);

    // Destroy the exporter
    lExporter->Destroy();

    // Destroy the SDK manager
    lSdkManager->Destroy();

    return 0;
}