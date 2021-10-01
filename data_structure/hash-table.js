const LinkedList = require("./linked-list");

function HashTable (n) {
    if(!n) throw new Error('n은 필수 입니다.');

    this.table = Array.from({length:n}, () => new LinkedList());

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

    function searchData (key, list) {
        let curNode = list.head;
        let index = 0;

        while(curNode) {
            if(curNode.data.key === key) {
                return {index:index, data:curNode.data};
            }
            index++;
            curNode = curNode.next;
        }
        return curNode;
    }

    this.put = function (key, value) {
        const indexOfMemory = hashToIndex(key, this.table.length);
        let searchResult = searchData(key, this.table[indexOfMemory]);

        if(!searchResult) {
            const nowNode = new Node(key,value);

            this.table[indexOfMemory].addFirst(nowNode);
            return nowNode;
        }

        searchResult.data.value = value;
        return searchResult.data;
    }

    this.get = function (key) {
        const indexOfMemory = hashToIndex(key, this.table.length);
        let searchResult = searchData(key, this.table[indexOfMemory]);

        if(!searchResult) {
            return -1;
        }

        return searchResult.data.value;
    }

    this.remove = function (key) {
        const indexOfMemory = hashToIndex(key, this.table.length);
        let searchResult = searchData(key, this.table[indexOfMemory]);

        if(!searchResult) {
            throw new Error('해당 key는 존재하지 않습니다.')
        }

        return this.table[indexOfMemory].remove(searchResult.index);
    }
}