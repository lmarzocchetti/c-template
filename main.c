#include <stdio.h>
#include <datatype99.h>
#include <interface99.h>

#define i_TYPE Floats, float
#include "stc/vec.h"

#include "mimalloc.h"
#include "sds.h"

// clang-format off
#define Shape_IFACE                      \
    vfunc( int, perim, const VSelf)      \
    vfunc(void, scale, VSelf, int factor)
// clang-format on

interface(Shape);

// Rectangle implementation
// ============================================================

typedef struct {
    int a, b;
} Rectangle;

int Rectangle_perim(const VSelf) {
    VSELF(const Rectangle);
    return (self->a + self->b) * 2;
}

void Rectangle_scale(VSelf, int factor) {
    VSELF(Rectangle);
    self->a *= factor;
    self->b *= factor;
}

impl(Shape, Rectangle);

// Triangle implementation
// ============================================================

typedef struct {
    int a, b, c;
} Triangle;

int Triangle_perim(const VSelf) {
    VSELF(const Triangle);
    return self->a + self->b + self->c;
}

void Triangle_scale(VSelf, int factor) {
    VSELF(Triangle);
    self->a *= factor;
    self->b *= factor;
    self->c *= factor;
}

impl(Shape, Triangle);

// Test
// ============================================================

void test(Shape shape) {
    printf("perim = %d\n", VCALL(shape, perim));
    VCALL(shape, scale, 5);
    printf("perim = %d\n", VCALL(shape, perim));
}

// clang-format off
datatype(
    BinaryTree,
    (Leaf, int),
    (Node, BinaryTree *, int, BinaryTree *)
);
// clang-format on

int sum(const BinaryTree *tree) {
    match(*tree) {
        of(Leaf, x) return *x;
        of(Node, lhs, x, rhs) return sum(*lhs) + *x + sum(*rhs);
    }

    // Invalid input (no such variant).
    return -1;
}

#define TREE(tree)                ((BinaryTree *)(BinaryTree[]){tree})
#define NODE(left, number, right) TREE(Node(left, number, right))
#define LEAF(number)              TREE(Leaf(number))

int main(void) {
    printf("Hello, World!\n");
    Shape r = DYN_LIT(Rectangle, Shape, {5, 7});
    Shape t = DYN_LIT(Triangle, Shape, {10, 20, 30});

    test(r);
    test(t);

    const BinaryTree *tree = NODE(NODE(LEAF(1), 2, NODE(LEAF(3), 4, LEAF(5))), 6, LEAF(7));

    /*
     * Output:
     * 28
     */
    printf("%d\n", sum(tree));
    return 0;
}