modded class ModifiersManager
{
    override void Init()
	{
		#ifdef DEVELOPER
		AddModifier(new TestDiseaseMdfr);
		#endif
		AddModifier(new BloodRegenMdfr);
		//AddModifier(new BoneRegen);
		//AddModifier(new Health);
		AddModifier(new SalineMdfr);
		AddModifier(new HealthRegenMdfr);
		AddModifier(new HungerMdfr);
		//AddModifier(new Shock);
		AddModifier(new ImmuneSystemMdfr);
		AddModifier(new StomachMdfr);
		AddModifier(new HeatComfortMdfr);
		AddModifier(new ThirstMdfr);
		AddModifier(new BleedingCheckMdfr);
		//AddModifier(new Blinded);
		//AddModifier(new BrokenArms);
		//AddModifier(new BrokenLegs);
		AddModifier(new VomitStuffedMdfr);
		AddModifier(new BurningMdfr);
		AddModifier(new FeverMdfr);
		AddModifier(new HeartAttackMdfr);
		AddModifier(new HemolyticReactionMdfr);
		AddModifier(new PoisoningMdfr);
		AddModifier(new StuffedStomachMdfr);
		//AddModifier(new Tremor);
		AddModifier(new UnconsciousnessMdfr);
		AddModifier(new ShockDamageMdfr);
		AddModifier(new CommonColdMdfr);
		AddModifier(new CholeraMdfr);
		AddModifier(new InfluenzaMdfr);
		AddModifier(new SalmonellaMdfr);
		AddModifier(new BrainDiseaseMdfr);
		AddModifier(new WetMdfr);
		AddModifier(new ImmunityBoost);
		AddModifier(new AntibioticsMdfr);
		AddModifier(new ToxicityMdfr);
		AddModifier(new BreathVapourMdfr);
		AddModifier(new ShockMdfr);
		AddModifier(new WoundInfectionMdfr);
		AddModifier(new CharcoalMdfr);
		AddModifier(new MorphineMdfr);
		AddModifier(new PainKillersMdfr);
		AddModifier(new EpinephrineMdfr);
	    AddModifier(new CannabisMdfr);

	}
}