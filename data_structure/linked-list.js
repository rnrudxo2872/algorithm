function LinkedList () {
    
    this.head = null;
    this.size = 0;
    
    function Node (data,next) {
        this.data = data;
        this.next = next || null;
    }

    this.add = function (data) {
        let newNode = new Node(data);
        this.size++;

        if(this.head === null) {
            this.head = newNode;
            return this.head;
        }
        
        let tail = this.head;
        
        while(tail.next) {
            tail = tail.next;
        }
        tail.next = newNode;
        return tail.next;
    }

    this.addAt = function(index, data) {
        let newNode = new Node(data);
        let curIdx = 0;
        let previousNode = null;
        let curNode = this.head;

        while(curNode) {
            if(curIdx === index){
                previousNode.next = newNode;
                newNode.next = curNode;

                return newNode;
            }
            curIdx++;
            previousNode = curNode;
            curNode = curNode.next;
        }

        return curNode;
    }

    this.getByIndex = function (index) {
        let curIdx = 0;
        let curNode = this.head;

        while(curNode) {
            if(curIdx === index) {
                return curNode;
            }
            curIdx++;
            curNode = curNode.next;
        }

        //may be null
        return curNode;
    }

    this.getByData = function (data) {
        let curIdx = 0;
        let curNode = this.head;
        
        while(curNode) {
            if(curNode.data === data) {
                return {index:curIdx, node:curNode};
            }

            curIdx++;
            curNode = curNode.next;
        }
        
        //may be null;
        return curNode;
    }

    this.remove = function (index) {
        let curIdx = 0;
        let previousNode = null;
        let curNode = this.head;

        while(curNode) {
            if(curIdx === index) {
                previousNode.next = curNode.next;
                return curNode;
            }

            curIdx++;
            previousNode = curNode;
            curNode = curNode.next;
        }

        //may be null
        return curNode;
    }

    this.removeByData = function (data) {
        let curIdx = 0;
        let previousNode = null;
        let curNode = this.head;

        while(curNode) {
            if(curNode.data === data) {
                previousNode.next = curNode.next;
                return {index:curIdx, node:curNode};
            }

            curIdx++;
            previousNode = curNode;
            curNode = curNode.next;
        }


        return curNode;
    }
}