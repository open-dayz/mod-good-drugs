class mommymilkies_opened: SodaCan_ColorBase
{
	
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(newModifiers.MDF_MILK))//effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier( newModifiers.MDF_MILK );
			consumer.GetModifiersManager().DeactivateModifier( eModifiers.MDF_TEMPERATURE );
		}
		consumer.GetModifiersManager().ActivateModifier( newModifiers.MDF_MILK );
		consumer.GetModifiersManager().ActivateModifier( eModifiers.MDF_TEMPERATURE );
	}
	

    bool IsMeleeFinisher()
	{
		return true;
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionWashHandsItem);
		AddAction(ActionForceDrink);
		AddAction(ActionDrinkCan);
	}
};

class mommymilkies : Edible_Base
{
override void Open()
	{
		//super.Open();
		ReplaceEdibleWithNew("mommymilkies");
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionRepairPart);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		AddAction(ActionDestroyPart);
	}
}