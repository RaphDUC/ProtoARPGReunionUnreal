// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/ReunionARPGAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UReunionARPGAttributeSet::UReunionARPGAttributeSet()
{
	// Default constructor
}

void UReunionARPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);

    // Set adjust code here
    //
    // Example:
    //
    // If a Max value changes, adjust current to keep Current % of Current to Max
    //
    // if (Attribute == GetMaxHealthAttribute())
    // {
    //     AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
    // }
}

void UReunionARPGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    FGSCAttributeSetExecutionData ExecutionData;
    GetExecutionDataFromMod(Data, ExecutionData);

    // Set clamping or handling or "meta" attributes here (like damages)

    // Example 1: Using helpers to handle each attribute in their own methods (See GSCAttributeSet.cpp)

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     HandleHealthAttribute(ExecutionData);
    // }

    // Example 2: Basic example to clamp the value of an Health Attribute between 0 and another MaxHealth Attribute

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
    // }
}

void UReunionARPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UReunionARPGAttributeSet, Health, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UReunionARPGAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UReunionARPGAttributeSet, Magic, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UReunionARPGAttributeSet, MaxMagic, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UReunionARPGAttributeSet, Speed, COND_None, REPNOTIFY_Always);
}

void UReunionARPGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UReunionARPGAttributeSet, Health, OldHealth);
}

void UReunionARPGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UReunionARPGAttributeSet, MaxHealth, OldHealth);
}

void UReunionARPGAttributeSet::OnRep_Magic(const FGameplayAttributeData& OldMagic)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UReunionARPGAttributeSet, Magic, OldMagic);
}

void UReunionARPGAttributeSet::OnRep_MaxMagic(const FGameplayAttributeData& OldMagic)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UReunionARPGAttributeSet, MaxMagic, OldMagic);
}

void UReunionARPGAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UReunionARPGAttributeSet, Speed, OldSpeed);
}
