const solution = (part, comp) => {
    comp.map(value => comp[value] = (comp[value] | 0) + 1);
    return part.find(value => !comp[value]--)
}