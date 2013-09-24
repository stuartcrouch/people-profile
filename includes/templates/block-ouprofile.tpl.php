<?php
// $Id: block.tpl.php,v 2.0 2010/06/08 09:00:00 laustin and PConolly $
?>
<!-- start block-ou_profile.tpl.php -->
    <div class="box <?php print ($block->module); print ($block->delta); ?>">
        <?php if ($block->subject): ?>
        <h2><?php print $block->subject ?></h2>
        <?php endif; ?>
        <?php print $block->content ?>
    </div>

<!-- /end block.tpl.php -->