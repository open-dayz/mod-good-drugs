class RandomSeedsPack extends SeedPackBase
{
	float rand_quantity = Math.RandomIntInclusive(1, 5);
	
	override void EmptySeedPack( PlayerBase player )
	{
		
		if (player)
		{
			vector pos = GetPosition();
		    ItemBase seed_a = GetGame().CreateObjectEx("TomatoSeeds", pos, ECE_PLACE_ON_SURFACE);
			ItemBase seed_b = GetGame().CreateObjectEx("PepperSeeds", pos, ECE_PLACE_ON_SURFACE);
			ItemBase seed_c = GetGame().CreateObjectEx("PumpkinSeeds", pos, ECE_PLACE_ON_SURFACE);
			ItemBase seed_d = GetGame().CreateObjectEx("ZucchiniSeeds", pos, ECE_PLACE_ON_SURFACE);
			seed_a.SetQuantity(rand_quantity);
			seed_b.SetQuantity(rand_quantity);
			seed_c.SetQuantity(rand_quantity);
			seed_d.SetQuantity(rand_quantity);
			GetGame().ObjectDelete( this );
		}
	}
}; 