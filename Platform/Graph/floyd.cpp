rep1n(isub, v){
		rep1n(i, v){
			rep1n(j, v){
				f[isub][i][j] = min(f[isub][i][j], g[i][j]);
				f[isub][i][j] = min(f[isub][i][j], f[isub - 1][i][isub] + f[isub - 1][isub][j]);
			}
		}
	}