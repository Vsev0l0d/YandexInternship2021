const module = {};

module.exports = async function(input) {
    const result = [];
    function FindRecoverablefiles(input) {
        input.size((size) => {
            for (let i = 0; i < size; i++){
                input.read(i, (file) => {
                    if (!(file === null || file === undefined)) {
                        if (typeof(file) === 'string') {
                            if(file.length !== (new Set(...file.split())).size)
                                result.push(file);
                        } else if ("size" in file) FindRecoverablefiles(file);
                    }
                });
            }
        });
        return new Promise(resolve => {
            setTimeout(() => resolve(), 500);
        });
    }
    await FindRecoverablefiles(input);
    return result.sort();
}