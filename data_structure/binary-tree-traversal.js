function Node (data,left,right) {
    this.data = data;
    this.left = left;
    this.right = right;
}

function Tree () {
    this.rootNode = null;

    this.setRoot = function (node) {
        this.rootNode = node;
    }

    this.getRoot = function () {
        return this.rootNode;
    }

    this.makeNode = function (data,left,right) {
        return new Node(data,left,right)
    }

    this.inOrder = function (node,arr) {
        if(node != null) {
            this.inOrder(node.left,arr);
            arr.push(node.data);
            this.inOrder(node.right,arr);
        }
    }
}

//inOrder
const tree = new Tree();

const n5 = tree.makeNode(5);
const n4 = tree.makeNode(4);
const n3 = tree.makeNode(3);
const n2 = tree.makeNode(2,n4,n5);
const n1 = tree.makeNode(1,n2,n3);
tree.setRoot(n1);

let arr = [];
tree.inOrder(tree.getRoot(),arr)
arr.forEach(val => console.log(val))