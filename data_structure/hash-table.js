function HashTable (n) {
    if(!n) throw new Error('n은 필수 입니다.');

    this.table = Array.from({length:n}, () => []);

    function Node(key, value) {
        if(key == null || value == null) throw new Error('잘못된 정보값 입니다.')

        this.key = key;
        this.value = value;
    }

    function getHash(key) {
        let hash = 0;
        for(let i = 0; i < key.length; ++i) hash += key[i].charCodeAt(0);

        return hash;
    }

    function hashToIndex(key,memorySize) {
        return getHash(key) % memorySize;
    }

    function findIndexHandler (node) {
        return node.key === this.toString()
    }

    this.put = function (key, value) {
        const indexOfMemory = hashToIndex(key, this.table.length);
        const findIdx = this.table[indexOfMemory].findIndex(findIndexHandler.bind(key));

        if(findIdx === -1) {
            const lengthAfterInsert = this.table[indexOfMemory].push(new Node(key,value));
            return this.table[indexOfMemory][lengthAfterInsert - 1];
        }

        this.table[indexOfMemory][findIdx].value = value;
        return this.table[indexOfMemory][findIdx];
    }

    this.get = function (key) {
        const indexOfMemory = hashToIndex(key, this.table.length);
        const findIdx = this.table[indexOfMemory].findIndex(findIndexHandler.bind(key));

        if(findIdx === -1) {
            return -1;
        }

        return this.table[indexOfMemory][findIdx].value;
    }

    this.remove = function (key) {
        const indexOfMemory = hashToIndex(key, this.table.length);
        const findIdx = this.table[indexOfMemory].findIndex(findIndexHandler.bind(key));

        if(findIdx === -1) {
            throw new Error('해당 key는 존재하지 않습니다.')
        }

        return this.table[indexOfMemory].splice(findIdx,1);
    }
}

const testTable = new HashTable(4);

testTable.put('first', '간달프');
testTable.put('first', '프프라');
testTable.put('0', 'ee')
testTable.put('1', 'ee')
testTable.put('2', 'ee')
testTable.put('3', 'ee')
testTable.put('5', 'ee')
testTable.put('4', 'ee')

console.log('삭제된 node => ',testTable.remove('1'))
console.log(testTable.get('1'))