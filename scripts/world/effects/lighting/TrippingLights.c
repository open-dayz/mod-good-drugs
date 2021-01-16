class TrippingLights extends PointLightBase
{	
	float m_Timer = 0;

	void TrippingLights()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo( 12 );
		SetBrightnessTo(0.38);
		SetDiffuseColor(0.2, 0.23, 0.25);
		SetCastShadow(true);
		EnableSpecular(true);
		EnableLinear(true);
		SetFlareVisible(false);
	}
	
	override void OnFrameLightSource(IEntity other, float timeSlice)
	{
		if ( GetGame()  &&  IsEnabled() )
		{
			SetAmbientColor(Math.RandomFloat01(), Math.RandomFloat01(), Math.RandomFloat01());
        	SetDiffuseColor(Math.RandomFloat01() / 2, Math.RandomFloat01() / 2, Math.RandomFloat01() / 2);
        // Set random lifetime between 1..3 seconds
        	SetFadeOutTime(4);
			m_Timer += timeSlice;
			
			DayZPlayer plr = GetGame().GetPlayer();
			if (plr)
			{
				vector pos = GetGame().GetCurrentCameraPosition();
				vector dir = GetGame().GetCurrentCameraDirection();
				int  r = Math.RandomIntInclusive(4, 8);
				vector trip = plr.GetPosition() + Vector( Math.RandomIntInclusive(-10, 10), Math.RandomIntInclusive(-10, 10), Math.RandomIntInclusive(1, 3));
				SetPosition(trip);

				float radius = Math.AbsFloat(Math.Tan(m_Timer * Math.PI2))
				SetRadiusTo( r *  radius );
			}
		}
	}
}
