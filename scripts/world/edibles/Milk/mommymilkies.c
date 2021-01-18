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
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDrinkCan);
		AddAction(ActionWashHandsItem)
		AddAction(ActionForceDrink)
	}
};

class mommymilkies : SodaCan_ColorBase
{
	override void Open()
	{
		//super.Open();
		ReplaceEdibleWithNew("mommymilkies_opened");
	}
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionDrinkCan);
		RemoveAction(ActionWashHandsItem)
		RemoveAction(ActionForceDrink)
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionRepairPart);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		AddAction(ActionDestroyPart);
		AddAction(ActionOpen);
	}
	
	bool IsMeleeFinisher()
	{
		return true;
	}
}