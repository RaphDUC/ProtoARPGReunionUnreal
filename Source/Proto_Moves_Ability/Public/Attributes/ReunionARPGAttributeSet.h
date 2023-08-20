// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "ReunionARPGAttributeSet.generated.h"

UCLASS()
class PROTO_MOVES_ABILITY_API UReunionARPGAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UReunionARPGAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health = 100.0;
    ATTRIBUTE_ACCESSORS(UReunionARPGAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth = 100.0;
	ATTRIBUTE_ACCESSORS(UReunionARPGAttributeSet, MaxHealth) 
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Magic)
    FGameplayAttributeData Magic = 100.0;
    ATTRIBUTE_ACCESSORS(UReunionARPGAttributeSet, Magic)

	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MaxMagic)
	FGameplayAttributeData MaxMagic = 100.0;
	ATTRIBUTE_ACCESSORS(UReunionARPGAttributeSet, MaxMagic)   
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Speed)
    FGameplayAttributeData Speed = 500.0;
    ATTRIBUTE_ACCESSORS(UReunionARPGAttributeSet, Speed)    

protected:
    
    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

    UFUNCTION()
    virtual void OnRep_Magic(const FGameplayAttributeData& OldMagic);

	UFUNCTION()
	virtual void OnRep_MaxMagic(const FGameplayAttributeData& OldMaxMagic);

    UFUNCTION()
    virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
	
	
};
