// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Building_Eescape/WorldPossition.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWorldPossition() {}
// Cross Module References
	BUILDING_EESCAPE_API UClass* Z_Construct_UClass_UWorldPossition_NoRegister();
	BUILDING_EESCAPE_API UClass* Z_Construct_UClass_UWorldPossition();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Building_Eescape();
// End Cross Module References
	void UWorldPossition::StaticRegisterNativesUWorldPossition()
	{
	}
	UClass* Z_Construct_UClass_UWorldPossition_NoRegister()
	{
		return UWorldPossition::StaticClass();
	}
	struct Z_Construct_UClass_UWorldPossition_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWorldPossition_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Building_Eescape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWorldPossition_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "WorldPossition.h" },
		{ "ModuleRelativePath", "WorldPossition.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWorldPossition_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWorldPossition>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UWorldPossition_Statics::ClassParams = {
		&UWorldPossition::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UWorldPossition_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UWorldPossition_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWorldPossition()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UWorldPossition_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWorldPossition, 3702901664);
	template<> BUILDING_EESCAPE_API UClass* StaticClass<UWorldPossition>()
	{
		return UWorldPossition::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWorldPossition(Z_Construct_UClass_UWorldPossition, &UWorldPossition::StaticClass, TEXT("/Script/Building_Eescape"), TEXT("UWorldPossition"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWorldPossition);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
