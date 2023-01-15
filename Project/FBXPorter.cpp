#include "FBXPorter.h"
#include <fbxsdk.h>

// called to Import File to MyScene
int FBXPorter::Import(const char* ImportFile)
{
    // Initialize the SDK manager
    FbxManager* lSdkManager = FbxManager::Create();

    // Create an FBX importer
    FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

    // Initialize the importer
    if (!lImporter->Initialize(ImportFile, -1, lSdkManager->GetIOSettings()))
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
    if (!lExporter->Initialize("_3DAPE.fbx", -1, lSdkManager->GetIOSettings()))
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

// After Editing Animation inside MyScene.fbx, It will export to a user specified directory
int FBXPorter::Export(const char* EXportFile)
{
    return 0;
}

