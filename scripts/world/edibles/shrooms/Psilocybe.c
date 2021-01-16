modded class PsilocybeMushroom
{
    override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(newModifiers.MDF_Psilocybe))//effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier( newModifiers.MDF_Psilocybe );
		}
		consumer.GetModifiersManager().ActivateModifier( newModifiers.MDF_Psilocybe );
	}
}
