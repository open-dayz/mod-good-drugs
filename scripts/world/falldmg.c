modded class DayZPlayerImplementFallDamage
{
    override void HandleFallDamage(float pHeight)
    {
        if (GetGame().IsServer())
		{
            PlayerBase pb = PlayerBase.Cast(m_Player);

            //on shrooms
            if( pb.GetModifiersManager() && pb.GetModifiersManager().IsModifierActive(newModifiers.MDF_Psilocybe) ) 
            {
                super.HandleFallDamage(3);
            }
			//! no dmg height
			if (pHeight <= FD_DMG_FROM_HEIGHT)
				return;

			vector posMS = m_Player.WorldToModel(m_Player.GetPosition());

			//! global dmg multiplied byt damage coef
			m_Player.ProcessDirectDamage( DT_CUSTOM, m_Player, "", FD_AMMO, posMS, DamageCoef(pHeight) );

			//! updates injury state of player immediately
			if (pb) pb.ForceUpdateInjuredState();
		}
        super.HandleFallDamage(pHeight);
    };
};