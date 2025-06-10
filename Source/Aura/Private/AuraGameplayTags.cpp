// Copyright Camperfire Studios


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/* Primary Attributes */

	GameplayTags.Attributes_Primary_Strength =					UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Primary_Intelligence =				UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Primary_Resilience =				UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Primary_Vigor =						UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"), FString("Reduces damage taken, improves block chance"));

	/* Secondary Attributes */
	GameplayTags.Attributes_Secondary_Armor =					UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_ArmorPenetration =		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_BlockChance =				UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_CriticalHitChance =		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_CriticalHitDamage =		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_CriticalHitResistance =	UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_HealthRegeneration =		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_ManaRegeneration =		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_MaxHealth =				UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_MaxMana =					UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("Reduces damage taken, improves block chance"));

	/* Vital Attributes */

	GameplayTags.Attributes_Secondary_Health =					UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Health"), FString("Reduces damage taken, improves block chance"));
	GameplayTags.Attributes_Secondary_Mana =					UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Mana"), FString("Reduces damage taken, improves block chance"));
}
