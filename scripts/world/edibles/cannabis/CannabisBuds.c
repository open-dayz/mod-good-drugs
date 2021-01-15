modded class Cannabis
{
	TrippingLights buzz;

	override bool CanBeCooked()
	{
		return true;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return true;
	}	
	
	override bool IsFruit()
	{
		return true;
	}

	override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(newModifiers.MDF_CANNABIS))//effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier( newModifiers.MDF_CANNABIS );
			consumer.GetModifiersManager().DeactivateModifier( eModifiers.MDF_TEMPERATURE );
		}
		consumer.GetModifiersManager().ActivateModifier( newModifiers.MDF_CANNABIS );
		consumer.GetModifiersManager().ActivateModifier( eModifiers.MDF_TEMPERATURE );
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatSmall);
	}
}
