int inv[mod+5];
void getInv(int mod)
{
	inv[1]=1;
	for(int i=2;i<mod;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}
