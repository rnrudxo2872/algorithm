const solution = (cloth) => {
    return Object.values(cloth.reduce((ret, clo) => {
        ret[clo[1]] = (ret[clo[1]] | 0) + 1;
        return ret
    },{})).reduce((ret,dic) => ret * (dic + 1),1) - 1
}